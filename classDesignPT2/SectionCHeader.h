#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Item {
public:
	Item(string name, long id, double price, int stock);
	string itemName;
	long ID;
	double p;
	int s;
};
ostream& operator <<(ostream& out, const Item& item);

class Order {
public:
	Order();

	vector<Item> getCurrentList() const;
	vector<int> getQuantityList() const;
	void addItem(Item item, int quantity);
	double getTotalPrice() const;

private:
	vector<Item> currentList;
	vector<int> quantityList;


};


class Store {
public:
	Store();
	vector<Item> inStock;
	vector<string> getItem() const;
	vector<int> getItemQuantity() const;
	void addStock(string nameOfItem, int QuantityOfItem);
	int getTotal() const;
	void processOrder(const Order& order);
private:
	vector<string> itemName;
	vector<int> itemQuantity;
};

ostream& operator<<(ostream& out, const Store& store);


