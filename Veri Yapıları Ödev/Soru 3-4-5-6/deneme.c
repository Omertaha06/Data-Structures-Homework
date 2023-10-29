#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define FILENAME "person.txt"

typedef struct list {
    char isim[50];
    int yas;
    int id;
    struct list *next;
}node;

// Dosyadan kişi bilgilerini okuyan fonksiyon
node *oku(const char *filename) {
    node *head = NULL;
    node *current = NULL;

    FILE *dosya = fopen(filename, "r");

    while (!feof(dosya)) {
        node *newPerson = (node *)malloc(sizeof(node));

        if (fscanf(dosya, "%s %d %d", newPerson->isim, &newPerson->yas, &newPerson->id) != 3) {
            free(newPerson);
            break;
        }

        newPerson->next = NULL;

        if (head == NULL) {
            head = newPerson;
            current = newPerson;
        } else {
            current->next = newPerson;
            current = newPerson;
        }
    }

    fclose(dosya);
    return head;
}


void yazdir(node *head) {
    printf("Dosyadan okunan kişiler:\n");// Bağlı listeyi ekrana yazdıran fonksiyon
    node *p = head;
    int count = 1;
    while (p != NULL) {
        printf("Kisi %d:\n", count);
        printf("Isim: %s\n", p->isim);
        printf("Yas: %d\n", p->yas);
        printf("Numara: %d\n\n", p->id);
        p = p->next;
        count++;
    }
}

node *ara(node *head, const char *arananIsim) {
    if (head == NULL) {
        printf("Liste bos.\n");
        return NULL;
    }

    node *p = head;

    while (p != NULL) {
        if (strcmp(p->isim, arananIsim) == 0) {
            printf("Aranan isim bulundu:\n");
            printf("Isim: %s\n", p->isim);
            printf("Yas: %d\n", p->yas);
            printf("Numara: %d\n", p->id);


            node *silDugumu = p->next;// Silme işlemi
            if (silDugumu != NULL) {
                p->next = silDugumu->next;
                free(silDugumu);
                printf("Aranan ismi içeren düğümün bir sonraki düğümü silindi.\n");
            } else {
                printf("Aranan ismi içeren düğümün bir sonraki düğümü bulunamadi.\n");
            }

            return p;
        }
        p = p->next;
    }

    printf("Aranan isim bulunamadi.\n");
    return NULL;
}



char *uzunbul(node *head, int *uzunluk) {
    if (head == NULL) {
        *uzunluk = 0;
        return NULL;
    }

    node *p = head;
    char *uzunisim = p->isim; //En uzun isim bulma
     *uzunluk = strlen(uzunisim);

    while (p != NULL) {
        int currentLength = strlen(p->isim);
        if (currentLength > *uzunluk) {
            uzunisim = p->isim;
            *uzunluk = currentLength;
        }
        p = p->next;
    }

    return uzunisim;
}

int main() {
    node *head = oku(FILENAME);
    int c=0;
    while(c!=-1){
        printf("Lutfen yapmak istediginiz islemi seciniz\n");
        printf("1-Yazdir\n2-En uzun isim bulma\n3-Ara ve ismi yazdir ve bi sonraki dugumu sil\nCikis icin -1 girin\n");
        scanf("%d",&c);

        if(c==1){
            yazdir(head);
        }
        else if(c==2){
            int uzunluk;
            char *uzunisim = uzunbul(head, &uzunluk);
            printf("\nEn uzun isim: %s\n", uzunisim);// en uzun isim yazdırma
            printf("Uzunluk: %d\n", uzunluk);

        }
        else if(c==3){
            char arananisim[50];
    printf("\nAranacak ismi girin: ");
    scanf("%s", arananisim);

    ara(head, arananisim);
        }
    }

    yazdir(head);
    printf("\nGuncellenmis liste\n");//Listede silinme işlemi yapıldıktan sonra tekrardan yazıp silinen isimi kontrol etme
    return 0;
}
