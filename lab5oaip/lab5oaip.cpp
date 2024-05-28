/*#include <iostream>
#include <list>
using namespace std;

class HashTable
{
private:
    static const int M = 10;
   list<int> table[M];

    int hash(int key)
    {
        return key % M;
    }

public:
    void insert(int key)
    {
        int index = hash(key);
        table[index].push_back(key);
    }

    bool search(int key)
    {
        int index = hash(key);
        for (int val : table[index])
        {
            if (val == key)
            {
                return true;
            }
        }
        return false;
    }

    void display()
    {
        for (int i = 0; i < M; ++i)
        {
            cout << "Ячейка " << i << ": ";
            for (int val : table[i])
            {
               cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "RU");
    HashTable ht;
    int n = 19;
    int rangeStart = 11000;
    int rangeEnd = 53000;

    for (int i = 0; i < n; ++i)
    {
        int randomValue = rand() % (rangeEnd - rangeStart + 1) + rangeStart;
        ht.insert(randomValue);
    }

   cout << "Хэш-таблица:" << endl;
    ht.display();


    int searchValue = 53041;
    if (ht.search(searchValue))
    {
        cout << "Элемент " << searchValue << " найден в таблице" << endl;
    }
    else {
       cout << "Элемент " << searchValue << " не найден в таблице" << endl;
    }

    return 0;
}*/

#include <iostream>
#include <vector>
#include <list>
#include <cstring>

using namespace std;

struct Record {
  char surname[50];
  int phone_number;
  char address[100];
};


int hash_function(int phone_number, int M) {
  return phone_number % M;
}


void insert(vector<list<Record>>& hash_table, const Record& record, int M) {
  int index = hash_function(record.phone_number, M);
  hash_table[index].push_back(record);
}


Record* search(vector<list<Record>>& hash_table, int phone_number, int M) {
  int index = hash_function(phone_number, M);
  for (auto& record : hash_table[index]) {
    if (record.phone_number == phone_number) {
      return &record;
    }
  }
  return nullptr;
}


void print_hash_table(vector<list<Record>>& hash_table) {
  for (size_t i = 0; i < hash_table.size(); ++i) {
    cout << "Bucket " << i << ": ";
    for (const auto& record : hash_table[i]) {
      cout << "{Surname: " << record.surname
        << ", Phone: " << record.phone_number
        << ", Address: " << record.address << "} ";
    }
    cout << endl;
  }
}

int main() {
  const int M = 10;
 vector<list<Record>> hash_table(M);

  
  Record records[] = {
      {"Ivanov", 1234567890, "Street 1"},
      {"Petrov", 2345678901, "Street 2"},
      {"Sidorov", 3456789012, "Street 3"},
      {"Smirnov", 4567890123, "Street 4"},
      {"Kuznetsov", 5678901234, "Street 5"},
      {"Popov", 6789012345, "Street 6"},
      {"Vasiliev", 7890123456, "Street 7"},
      {"Pavlov", 8901234567, "Street 8"},
      {"Semenov", 9012345678, "Street 9"}
  };

  
  for (const auto& record : records) {
    insert(hash_table, record, M);
  }

 
  print_hash_table(hash_table);

 
  int phone_number_to_search = 2345678901;
  Record* found_record = search(hash_table, phone_number_to_search, M);
  if (found_record) {
    cout << "found: {Surname: " << found_record->surname
      << ", Phone: " << found_record->phone_number
      << ", Address: " << found_record->address << "}" << endl;
  }
  else {
    cout << "not found" << endl;
  }

  return 0;
}
