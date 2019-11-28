
extern char *yytext;		/* declared by scanner */
extern int yylineno;		/* declared in scanner.l */

typedef struct ArraySig ArraySig;
//typedef struct Type Type;
typedef struct TypeList TypeList;
typedef struct TableEntry TableEntry;
typedef struct SymbolTable SymbolTable;
typedef struct IdList IdList;
typedef struct Value Value;
typedef struct Attribute Attribute;
typedef struct Expr Expr;
typedef struct ExprList ExprList;
typedef struct FunctionInnvocation FunctionInnvocation;
extern SymbolTable* symbol_table;

struct SymbolTable {
	char name[32];
	char type[32];
	int address;
	char scope[32];
	char pre_scope[32];
	int level;
	int pos;
	int depth;
	TableEntry** Entries;
};
struct TableEntry{
	char name[32];
	char type[32];
	char scope[32];
	int address;
	float value;
	char sval[32];
	float array[32];
};




SymbolTable* BuildSymbolTable();
void InsertTableEntry(SymbolTable*, TableEntry*);
TableEntry* BuildTableEntry(char*, char*, char*, int);
void PrintSymbolTable(SymbolTable*);
int FindEntryInScope(SymbolTable*,char*, char*);
int FindEntryInGlobal(SymbolTable*,char*);
int FindEntryLoopVar(SymbolTable*,char*);
void UpdateType(SymbolTable*, char*, int);
int FindEntryInAll(SymbolTable*, char*);
void PrintValue(Value*, char*);
void popall(SymbolTable*);
