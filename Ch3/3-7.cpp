#include<iostream>
#include<string>

using namespace std;

class Animal
{
public:

	enum Type { Dog = 0, Cat = 1 };
	string name;
	int type; // 0 dog; 1 cat
	Animal* next;

	Animal(string n, int t = Dog)
	{
		name = n;
		type = t;
		next = NULL;
	}

	~Animal()
	{}
};

Animal* addToTail(Animal* head, string name, int type)
{
	Animal* a = new Animal(name, type);
	if (head == NULL)
		return a;

	Animal* p = head;
	while(p->next != NULL)
		p = p->next;

	p->next = a;
	return head;
}

class AnimalShelter
{
private:
	Animal* _animal;

public:
	AnimalShelter()
	{}

	~AnimalShelter()
	{}

	void push(string name, int type)
	{
		_animal = addToTail(_animal, name, type);
	}

	Animal* popAny()
	{
		Animal* n = _animal;
		_animal = _animal->next;
		return n;
	}

	Animal* popDog()
	{
		Animal* n = _animal;
		Animal* prev = NULL;
		while (n->type != Animal::Dog)
		{
			prev = n;
			n = n->next;
		}

		if (prev != NULL)
			prev->next = n->next;
		else
			_animal = n->next;
		
		return n;
	}

	Animal* popCat()
	{
		Animal* n = _animal;
		Animal* prev = NULL;
		while (n->type != Animal::Cat)
		{
			prev = n;
			n = n->next;
		}

		if (prev != NULL)
			prev->next = n->next;
		else
			_animal = n->next;
		
		return n;	
	}
};

void main()
{
	AnimalShelter as;
	as.push("Dog1", Animal::Dog);
	as.push("Cat1", Animal::Cat);
	as.push("Dog2", Animal::Dog);
	as.push("Dog3", Animal::Dog);
	as.push("Cat2", Animal::Cat);

	Animal* any = as.popAny();
	Animal* dog = as.popDog();
	Animal* cat = as.popCat();

	cout << any->name << ", " << dog->name << ", " << cat->name << "\n";
	system("pause");
}
