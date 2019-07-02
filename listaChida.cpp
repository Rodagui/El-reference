#include <iostream>
using namespace std;

template<class T>
struct Nodo{
	Nodo* sig, *ant;
	T val;
	Nodo() : sig(NULL), ant(NULL){}
	Nodo( T v ) : val(v), sig(NULL), ant(NULL){}
};

template<class T>
struct Lista{
	Nodo<T>* head;
	Nodo<T>* tail;
	int sz;

	Lista() : head(NULL), tail(NULL), sz(0){}

	void Insert( Nodo<T>* pos, T v ){ /*si no es null siempre se inserta a la derecha*/
		sz++;
		Nodo<T>* tmp = new Nodo<T>(v);
		if( !head ){
			head = tail = tmp;
			return;
		}
		if( !pos ){
			tmp->sig = head;
			head->ant = tmp;
			head = tmp;
			return;
		}
		if( pos->sig )
			pos->sig->ant = tmp;
		tmp->sig = pos->sig;
		tmp->ant = pos;
		pos->sig = tmp;
	}

	void InsertHead( T v ){
		if( !head ){
			Insert(NULL, v);
			return;
		}
		Insert( NULL, v );
	}

	void InsertTail( T v ){
		if( !tail ){ //lista vacía
			Insert(NULL, v);
			return;
		}
		Insert( tail, v );
		tail = tail->sig;
	}

	Nodo<T>* Query( T val ){
		Nodo<T>* cpy = head;
		while( cpy ){
			if( cpy->val == val )
				return cpy;
			cpy = cpy->sig;
		}
		return NULL;
	}

	void Delete( Nodo<T>* node ){
		if( node == NULL ) return;
		if( node->sig )
			node->sig->ant = node->ant;	
		if( node->ant )
			node->ant->sig = node->sig;	
		if( node == head )
			head = node->sig;
		if( node == tail )
			tail = node->ant;
		sz--;
	}

	void Print(){
		Nodo<T>* cpy = head;
		while( cpy ){
			cout << cpy->val << endl;
			cpy = cpy->sig;
		}
	}

	int size(){
		return sz;
	}
};

int main(){
	Lista<string> list;
	list.InsertHead( "Ivan" );
	list.InsertHead( "Juan" );
	list.InsertTail( "Giovanni" );
	list.InsertTail( "John" );
	list.InsertTail( "Johan" );
	list.Insert( list.tail->ant, ("Jean") );

	list.Print();
	cout << "Size: " << list.size() << endl << endl;
	cout << endl;
	if( list.Query( "Joan" ) )
		cout << "Joan está en la lista" << endl;
	else
		cout << "Joan NO está en la lista" << endl;

	if( list.Query( "Ivan" ) )
		cout << "Ivan está en la lista" << endl;
	else
		cout << "Ivan NO está en la lista" << endl;
	cout << endl;

	cout << "Borra Juan" << endl;
	list.Delete( list.head );
	list.Print();
	cout << endl;

	cout << "Borra John:" << endl;
	list.Delete( list.Query( "John" ) );
	list.Print();
	cout << endl;

	cout << "Borra Luis:" << endl;
	list.Delete( list.Query( "Luis" ) );
	list.Print();
	cout << endl;

	cout << "Borra Johan:" << endl;
	list.Delete( list.tail );
	list.Print();
	cout << endl;

	cout << "Borra Jean:" << endl;
	list.Delete( list.tail );
	list.Print();
	cout << endl;

	cout << "Size: " << list.size() << endl << endl;

	cout << "Borra Giovanni:" << endl;
	list.Delete( list.tail );
	list.Print();
	cout << endl;

	cout << "Borra Ivan:" << endl;
	list.Delete( list.tail );
	list.Print();
	cout << endl;

	cout << "Size: " << list.size() << endl << endl;
	return 0;
}
