#include <iostream>
#include <list>
#include <unordered_map>
#include <cmath>

using namespace std;

class Person 
{
public:
	string idNumber;
	string fullName;
	string birthDate;
	string adress;

Person(string idNumber, string fullName, string birthDate, string adress) {
	this->idNumber = idNumber;
	this->fullName = fullName;
	this->adress = adress;
	this->birthDate = birthDate;
}
};

class LruCache 
{
private:
	int capacity;
	double loadFactor;
	list<Person> cacheList;
	unordered_map<string, list<Person>::iterator> cacheMap;
public: 
	LruCache(int capacity, double loadFactor) {
		this->capacity = capacity;
		this->loadFactor = loadFactor;
	}

	Person* getPerson(string idNumber) {
		if (cacheMap.find(idNumber) == cacheMap.end())
		{
			return NULL;
		}
		list<Person>::iterator itr = cacheMap[idNumber];
		Person person = *itr;
		std::cout<< "person aq" << person.fullName << endl;
		cacheList.erase(itr);
		cacheList.push_front(person);
		cacheMap[idNumber] = cacheList.begin();

		return &cacheList.front();
	}
    // Yeni bir kişiyi cache'e ekleme
    void addPerson(Person person) {
        // Cache dolu ise en son kullanılan kişiyi sil
        if (cacheList.size() >= capacity) {
            Person lastPerson = cacheList.back();
            cacheList.pop_back();
            cacheMap.erase(lastPerson.idNumber);
        }

        // Yeni kişiyi cache'in başına ekle
        cacheList.push_front(person);
        cacheMap[person.idNumber] = cacheList.begin();
    }	
};

unsigned long long hashString(string str) {
	unsigned long long hashVal = 0;
	int p = 53;
	unsigned long long p_pow = 1;
	int m = str.size();

	for (int i = 0; i < m; i++) {
		hashVal = (hashVal + (str[i] - '0' + 1) * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}

	return hashVal;
}

int findSmallestPrime(int n) {
	while (true) {
		bool isPrime = true;

		for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			isPrime = false;
			break;
			}
		}
		if (isPrime) {
		return n;
		}
		n++;
	}
}

int main(int argc, char const *argv[])
{
	int cacheSize;
	std::cout << "please input cache size" << std::endl;
	std::cin >> cacheSize;

	double loadFactor = 0.60;
	int tableSize;
	std::cout << "please input table size" << std::endl;
	std::cin >> tableSize;
	
	tableSize = findSmallestPrime(tableSize);

	LruCache cache(cacheSize, loadFactor);

	while (true)
	{
		int choice;
		std::cout << endl;
        std::cout << "1. Add Person" << endl;
        std::cout << "2. Search for Person" << endl;
        std::cout << "3. Exit program" << endl;
        std::cout << "Make your choice: ";
        std::cin >> choice;		

        if (choice == 1) {
            string idNumber, fullName, birthDate, adress;
            std::cout << "Kimlik No: ";
            std::cin >> idNumber;
            std::cout << "Ad Soyad: ";
            std::cin >> fullName;
            std::cout << "Doğum Tarihi: ";
            std::cin >> birthDate;
            std::cout << "Adres: ";
            std::cin >> adress;		


            Person person(idNumber, fullName, birthDate, adress);
            cache.addPerson(person);
            cout << "Kişi başarıyla eklendi." << endl;
		} else if (choice == 2) {
            string idNumber;
            cout << "Kimlik No: ";
            cin >> idNumber;

            Person* person = cache.getPerson(idNumber);
            if (person != NULL) {
                cout << "Kimlik No: " << person->idNumber << endl;
                cout << "Ad Soyad: " << person->fullName << endl;
                cout << "Doğum Tarihi: " << person->birthDate << endl;
                cout << "Adres: " << person->adress << endl;
            } else {
                cout << "Kişi bulunamadı." << endl;
            }
        } else if (choice == 3) {
            break;
        } else {
            cout << "Geçersiz seçim. Tekrar deneyin." << endl;
        }	
	}

	return 0;
}

