enum declarationkind {
	DECLTYPE,
	DECLOBJECT,
	DECLFUNC,
	DECLCONST,
	DECLBUILTIN,
};

enum linkage {
	LINKNONE,
	LINKINTERN,
	LINKEXTERN,
};

struct declaration {
	enum declarationkind kind;
	enum linkage linkage;
	struct type *type;
	struct value *value;
	struct list link;
	int align;  /* may be more strict than type requires */
	_Bool tentative, defined;
};

struct scope;
struct function;

extern struct declaration builtinvalist;
extern struct declaration builtinvastart;
extern struct declaration builtinvaarg;
extern struct declaration builtinvacopy;
extern struct declaration builtinvaend;
extern struct declaration builtinoffsetof;
extern struct declaration builtinalloca;

struct declaration *mkdecl(enum declarationkind, struct type *, enum linkage);
_Bool decl(struct scope *, struct function *);
struct type *typename(struct scope *);

struct expression;
struct declaration *stringdecl(struct expression *);

void emittentativedefns(void);
