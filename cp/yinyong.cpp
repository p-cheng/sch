#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
struct teacher {
    int id;
    char name[64];
};


int get_mem(struct teacher **tpp)
{
    struct teacher *tp = NULL;
    tp = (struct teacher *)malloc(sizeof(struct teacher));
    if(tp == NULL)
    {
        return -1;
    }
    strcpy(tp->name,"das");
    tp->id = 100;
    *tpp  =tp;
    return 0;
}


void free_teacher(struct teacher **tpp)
{
    if(tpp == NULL)
    {
        return ;
    }
    struct teacher *tp =*tpp;
    if(tp !=NULL)
    {
        free(tp);
        *tpp = NULL;
    }

}
int get_mem2(struct teacher * &tp)
{
    tp = (struct teacher*)malloc(sizeof(struct teacher));
    if(tp == NULL)
    {
        return -1;
    }
    tp->id = 20;
    strcpy(tp->name,"wang");
    return 0;
}
void free_teacher2(struct teacher * &tp)
{
    if(tp != NULL)
        free(tp);
    tp = NULL;
}

int main()
{
    struct teacher *tp = NULL;

    get_mem(&tp);
    cout << "id = " << tp->id << ", name=" << tp->name <<endl;
    free_teacher(&tp);
    get_mem2(tp);
    cout << "id = " << tp->id << ", name=" << tp->name <<endl;
    free_teacher2(tp);
    return 0;
}
