#include "hash.h"

int main() {
	Hash table;
	table.insert("ubin",387316132);
	table.insert("imin", 945257831);
	table.insert("susu", 339527683);
	table.insert("uboa", 994957929);
	table.insert("thincho", 973062777);
	table.insert("itsupport", 969430396);
	table.insert("hoa", 357644310);
	table.insert("another", 963975329);
	table.insert("a1", 1);
	table.insert("a2", 1);
	table.insert("a3", 6);
	
	table.deleteKey("itsupport", 969430396);
	table.deleteKey("a1", 1);
	table.deleteKey("a3", 6);
	table.deleteKey("ubin", 387316132);
	table.deleteKey("susu", 339527683);
	
	system("pause");

}