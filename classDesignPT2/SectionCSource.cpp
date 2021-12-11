#include "SectionCHeader.h"
using namespace std;

Item::Item(string name, long id, double price, int stock)
	:itemName{ name }, ID{ id }, p{ price }, s{ stock } {}

ostream& operator <<(ostream& out, const Item& item) {
	out << "Item Details: " << "\n" << "Name: " << item.itemName << "\n" << "ID: " << item.ID << "\n" << "Price: " << item.p << "\n" << "In Stock: " << item.s << "\n";
	return out;
}

Store::Store()
	: itemName(), itemQuantity() {}

void Store::addStock(string nameOfItem, int QuantityOfItem) {
	itemName.push_back(nameOfItem);
	itemQuantity.push_back(QuantityOfItem);
}


vector<string> Store::getItem() const{
	return itemName;
}

vector<int> Store::getItemQuantity() const {
	return itemQuantity;
}

	int Store::getTotal() const {
	vector<int> itemName = getItemQuantity();
	int count = 0;

	for (int i = 0; i < itemName.size(); i++) {
		count += itemName.at(i);
	}
	return count;
}



ostream& operator<<(ostream& out, const Store& store) {
	vector<string> itemName = store.getItem();
	vector<int> itemQuantity = store.getItemQuantity();
	cout << "Store: " << "\n";
	for (int i = 0; i < itemQuantity.size(); i++) {
		out << (itemName.at(i)) << " x " << (itemQuantity.at(i)) << "\n";
	}
	return out;
}

void Store::processOrder(const Order& order) {
	vector<Item> orderList = order.getCurrentList();
	vector<int> orderQuantity = order.getQuantityList();
	for (int i = 0; i < orderList.size(); i++) {
		string orderName = orderList.at(i).itemName;
		for (int j = 0; j < getItem().size(); j++) {
			if (orderName == getItem().at(j)) {
				itemQuantity.at(j) -= orderQuantity.at(i);
			}
		}
	}
}


Order::Order()
	: currentList() {}

vector<Item> Order::getCurrentList() const{
	return currentList;
}

vector<int> Order::getQuantityList() const {
	return quantityList;
}

void Order::addItem(Item item, int quantity) {
	if (currentList.size() >= 10) {
		cout << "You can't exceed 10 items in your order." << "\n";
	}
	else {
		 currentList.push_back(item);
		 quantityList.push_back(quantity);
	}

}


double Order::getTotalPrice() const {
	vector<Item> currentList = getCurrentList();
	double total = 0;
	for (int i = 0; i < currentList.size(); i++) {
		 total += (currentList.at(i)).p * (currentList.at(i)).s;
	}
	return total;
}




