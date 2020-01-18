extern int yylineno;
extern FILE* outfp;

extern struct SymbolTable *symbolTable;	// main symbol table
extern char fileName[256];
extern int exe_spcae;
extern unsigned int ieee[100000];
extern int op_type;
extern int pre_rec;
extern int if_cnt;
extern int inexp;
extern int infunc_exp;
typedef unsigned uint;
typedef unsigned long long ull;
//--------------------------------------------------
#define FLT_SIGN_BITS 1           // float signed     field using bit
#define FLT_EXP_BITS  8           // float exponment  field using bits
#define FLT_MAT_BITS  23          // float mantissa   field using bits

#define FLT_SIGN_MASK 0x80000000 // float signed bit
#define FLT_EXP_MASK  0x7F800000 // float exponment bits
#define FLT_MAT_MASK  0x007FFFFF // float mantissa bits


void GenProgramStart(char*);
void init_space();
void recover_setting();
void init_func(SymbolTable*, char*);
void end_func(SymbolTable*, char*);
void push_value_to_stack(SymbolTable*,Value*, int, int);
//void print_outcome();
TableEntry* FindEntryInFunc(SymbolTable*, char*);
void Build_printint(SymbolTable*);
void Build_printreal(SymbolTable*);
void Build_printstring(SymbolTable*);
void Print_Int();
void Print_Real();
void Print_String();
void ready_printi(int);
void ready_printr(int);
void ready_prints(int, char*);
void last_for_print(int, char**);
char* compare_two(Value*, Value*, char*);
int Request_array_space(SymbolTable*, Type*, int, int, float*);
void Get754Field32(float, uint*, uint*, uint*);
unsigned int Set754Field32(uint, uint, uint);
unsigned int assign_float(float, int);
unsigned int re_print_float(float, int);
void change_para_value(SymbolTable*, char*);
void Mul_Div_prepare(int);
void Add_Sub_prepare(int);
void Exe_mul_div(int, char*, Value*);
void Exe_add_sub(int, char*, Value*);
void cmp_prepare();
void Exe_cmp(char*, int);
void IF_decide();
void Compute_Array_Space(int*, int, Value*);
void Assign_for_array(TableEntry*);
void Assign_for_arrayF(TableEntry*);
void Compute_Array_Space_R(int*, int, Value*);
void Find_array_value(TableEntry*);
void Find_array_valueF(TableEntry*);
void Prevent_rec(int, int);
void Prevent_rec_end();
void Reload_para(SymbolTable*, char*);


