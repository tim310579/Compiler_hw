extern char *yytext;		/* declared by lex */
extern int yylineno;		/* declared in lex.l */
extern int Opt_D;		/* declared in lex.l */
extern int loop_cnt;
extern char* fn;

typedef struct ArraySig ArraySig;
typedef struct Type Type;
typedef struct TypeList TypeList;
typedef struct TableEntry TableEntry;
typedef struct SymbolTable SymbolTable;
typedef struct IdList IdList;
typedef struct Value Value;
typedef struct Attribute Attribute;
typedef struct Expr Expr;
typedef struct ExprList ExprList;
typedef struct FunctionInnvocation FunctionInnvocation;
typedef struct Var Var;
extern SymbolTable* symbol_table;
struct SymbolTable {
	int current_level;
	int pos;
	int capacity;
	char scope[32];
	TableEntry** Entries;
} ;

struct TableEntry {
	char name[33];
	char scope[32];
	char ret[32];
	int para_cnt;
	char** para;
	int level;
	int init;
	int line;
	int arr_dim;
	int arr_range[10];
	int* iarray;
	float* farray;
	char* sarray;
	Type* type;
	Value* value;
	Var* var;
};
struct Var{
	char name[32];
	Type* type;
	Value* value;
	int tail_cnt;
	int tail[20];
};
struct ArraySig{
	int capacity;
	ArraySig* next_dimension;
};

struct Attribute{
	Value* val;
	TypeList* type_list;
};

struct Type{
	char name[32];
	int arr_dim;
	int arr_range[32];
};

struct TypeList{
	int current_size;
	int capacity;
	Type** types;
};

struct Expr{
	char kind[16]; //var,func,const
	char name[33];
	Type* type;
	TableEntry* entry;
	int current_dimension;
	TypeList* para;
};

struct Value{
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
};

SymbolTable* BuildSymbolTable();
void InsertTableEntry(SymbolTable*,TableEntry*);
void InsertTableEntryFromList(SymbolTable*,IdList*,const char*,Type*,Attribute*);
void PopTableEntry(SymbolTable*);
void PopTableEntryByName(SymbolTable*,char*);
TableEntry* BuildTableEntry(char*, int, Type*, int);

void PrintSymbolTable(SymbolTable*);
void PrintLevel(int);
char* PrintType(const Type*,int);
void PrintIdList(IdList*);
void PrintAttribute(Attribute*);

Attribute* BuildConstAttribute(Value*);
Attribute* BuildFuncAttribute(TypeList*);

Expr* FindVarRef(SymbolTable*,char*);
Expr* FindFuncRef(SymbolTable*,char*);
Expr* ConstExpr(Value*);
Expr* FunctionCall(char*,ExprList*);
Expr* RelationalOp(Expr*,Expr*,char*);
Expr* MulOp(Expr*,Expr*,char*);
Expr* AddOp(Expr*,Expr*,char*);
Expr* BooleanOp(Expr*,Expr*,char*);

ExprList* BuildExprList(ExprList*,Expr*);

TableEntry* FindEntryInScope(SymbolTable*,char*);
TableEntry* FindEntryInGlobal(SymbolTable*,char*);
TableEntry* FindEntryLoopVar(SymbolTable*,char*);

IdList* BuildIdList();
void ResetIdList(IdList*);
void InsertIdList(IdList*,char*);

Type* BuildType(char*);
TableEntry* AddArrayToType(SymbolTable*, int);

TypeList* AddTypeToList(TypeList*,Type*,int);
TypeList* ExtendTypelist(TypeList*,TypeList*);

Value* BuildValue(char*, char*);
Value* SubOp(Value*);

int CheckConstAssign(Expr*);
int CheckType(Expr*,Expr*);
int CheckFuncParaNum(Expr*);
int CheckFuncRet(Type*,Expr*);
int CanCoerce(Expr*,Expr*);
int CheckSimple(Expr*);
int CheckFilename(char*,char*);

void UpdateType(SymbolTable*, Type*, int line);
int IsFunction(SymbolTable*, char*);
void UpdateFunctionRet(SymbolTable*, Type*, int);
void AddparaToFunc(SymbolTable*, char*, int);
Type* BuildArrayType(char*, int, int);
char* itoa(int);
Value* Addtwo(Value*, Value*, char*, int);
Value* Multwo(Value*, Value*, char*, int);
//void AddparaToFunc(SymbolTable*, int);
void UpdateValue(SymbolTable*, Value*);
void UpdateIndex(TableEntry*, int*, int);
void UpdateIndexValue(SymbolTable*, Value*);
