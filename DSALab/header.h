typedef struct Info {
    char name[20];
    char tel[12];
    char email[30];
    struct Info *next;
} Info;

Info* makeNewNode();
void print1Info(Info* xxx);
void printAllInfo(Info* xxx);
void insertAtFirst();
void freeInfo();
void insertAtTail();
void deleteFirst();
Info *reverse_Node();

