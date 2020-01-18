extern char *yytext;		/* declared by lex */
extern int yylineno;		/* declared in lex.l */

typedef struct Type Type;
typedef struct TableEntry TableEntry;
typedef struct SymbolTable SymbolTable;
typedef struct Value Value;
extern SymbolTable* symbol_table;
extern int exe_space;

struct SymbolTable {
	int current_level;
	int pos;
	int cnt_upd;
	int capacity;
	char** scopes;
	char scope[32];
	char pre_scope[32];
	TableEntry** Entries;
} ;

struct TableEntry {
	char name[33];
	char scope[32];
	char ret[32];
	int para_cnt;
	char** para;
	char* paratype;
	int level;
	int cnt_upd;
	int init;
	int line;
	int arr_dim;
	int arr_range[32];
	int* iarray;
	float* farray;
	char* sarray;
	Type* type;
	Value* value;
	int exe_space;
};

struct Type{
	char name[32];
	int arr_dim;
	int arr_range[32];
	int array_cnt;	//count array numbers
	int array_space;
	int array_length[32];
};


struct Value{
	float array_all[100000];
	Type* type;
	char name[32];
	int ival;
	double dval;
	char* sval;
	int tail_cnt;	//dimension
	int tail[32];
	int** index;
	double** indexf;
	int has_tail;
	int is_array;
	int para_cnt;
	int para[32];
	double paraf[32];
	char ret[32];
	int both;
	int is_const;
	int array_space;
	int array_length[32];
};

SymbolTable* BuildSymbolTable();
void InsertTableEntry(SymbolTable*,TableEntry*);

TableEntry* BuildTableEntry(char*, char*, int, Type*, int, int);

void PrintSymbolTable(SymbolTable*);
void PrintLevel(int);

TableEntry* FindEntryInScope(SymbolTable*,char*);
TableEntry* FindEntryInGlobal(SymbolTable*,char*);

Type* BuildType(char*);

Value* BuildValue(char*, char*);

void UpdateType(SymbolTable*, Type*, int line);
int IsFunction(SymbolTable*, char*);
int IsProcedure(SymbolTable*, char*);
void UpdateFunctionRet(SymbolTable*, Type*, int);
void AddparaToFunc(SymbolTable*, char*, int);
Type* BuildArrayType(char*, int, int);
char* itoa(int);
Value* Addtwo(Value*, Value*, char*, int);
Value* Multwo(Value*, Value*, char*, int);
void UpdateValue(SymbolTable*, char*, Value*);
void UpdateIndex(TableEntry*, int*, int);
void UpdateIndexValue(SymbolTable*, Value*);
Value* BuildValueTail(char*);
Value* ReturnIdValue(SymbolTable*, char*, int*, int, char);
Value* BuildNegValue(char*, char*);
TableEntry* FindEntryFuncInScope(SymbolTable*, char*);
char* FindTypeOfPara(SymbolTable*, char*, int);
Value* BuildFuncId(SymbolTable*, char*, char*, int);
void BuildProcId(SymbolTable*, char*, char*, int);
void CopyValue(Value*, Value*);
int CheckAssignCanOrNot(Value*, Value*);
