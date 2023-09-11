#include <stdio.h>
#include <stdlib.h>
#define N 2
struct musteri
{
    char soyisim[10],isim[10];
    int kahvalti;//eger 1 ise kahvalti yapmistir 0'sa yapmamistir
    int aksamyemegi;//eger 1 ise kahvalti yapmistir 0'sa yapmamistir
    int otel;//3= 3 yildizli, 5=5yildizli
    int kackisi;//1 veya 2 kisilik olacak
    float ucret;
};
void maxucret(struct musteri musteriler[N])
{
    int i;
    float maxucret=musteriler[0].ucret;
    for(i=0; i<N; i++)
    {
        if(musteriler[i].ucret>maxucret)
        {
            maxucret=musteriler[i].ucret;
        }
    }

    printf("%d. Musteri %.2f ucret odeyerek en cok ucreti odemistir.",i,maxucret);


}
void musteribilgilerinibastir(struct musteri musteriler[N])
{
    int i;
    printf("Musterilere ait bilgiler\n");
    printf("--------------------------\n");



    printf("\n");

    for(i=0; i<N; i++)
    {
        printf("%d. Musteri\n",i+1);
        printf("Isim:%s\nSoyisim:%s\n%d Yildizli Otel\nOdenilen Ucret:%.2f\n",musteriler[i].isim,musteriler[i].soyisim,musteriler[i].otel,musteriler[i].ucret);
        printf("--------------------------\n");
    }
    printf("\n");


}
void kisitercihleri(struct musteri musteriler[N],int kahv,int aks)
{
    int i;
    srand(time(0));
    for(i=0; i<N; i++)
    {
        musteriler[i].kackisi=rand()%2+1;//1 veya 2 sayisini uretir
        if(musteriler[i].kackisi==2)
        {
            musteriler[i].ucret=musteriler[i].ucret+kahv+aks;
        }
    }
    printf("\n");
    printf("Otel odalari 1 ve 2 kisiliktir.Rezervasyon paketlerinde kisi sayisi sistem tarafindan verilir.\n\n");
    for(i=0; i<N; i++)
    {
        printf("\n*****************************************************\n");
        if(musteriler[i].kackisi==1)
        {
            printf("%d. Musteri 1 kisilik oda icin ucret odemesi yapcaktir.",i+1);
        }
        else
        {
            printf("%d. Musteri 2 kisilik oda icin ucret odemesi yapcaktir.",i+1);
        }
    }
    printf("\n*****************************************************\n\n");
}
void oteltercihleri(struct musteri musteriler[N])
{
    int i;
    printf("Musterilerin 3 veya 5 yildizli otel tercihleri\n");
    for(i=0; i<N; i++)
    {
        printf("%d.Musteri kac yildizli oteli tercih eder? :\n",i+1);
        scanf("%d",&musteriler[i].otel);
        if((musteriler[i].otel)!=3 && (musteriler[i].otel)!=5)
        {
            printf("yanlis otel secimi!!!");
        }
    }
    for(i=0; i<N; i++)
    {
        if(musteriler[i].otel==3)
        {
            musteriler[i].ucret+=500;
        }
        else
        {
            musteriler[i].ucret+=800;
        }
    }
    printf("\n\n");
    printf("-----------------------------------------------------------------------\n");

}
void musteriyemektercihleri(struct musteri musteriler[N],int kahv,int aks)
{
    int i;
    musteriler[i].ucret=0;
    srand(time(0));//sistem saati sifirlar
    for(i=0; i<N; i++)
    {
        musteriler[i].kahvalti=rand()%2;//yemek tercihlerine random deger atadim
        musteriler[i].aksamyemegi=rand()%2;
        if(musteriler[i].kahvalti==1)
        {
            musteriler[i].ucret+=kahv;
        }
        if(musteriler[i].aksamyemegi==1)
        {
            musteriler[i].ucret+=aks;
        }
    }
    printf("\n");
    printf("-----------------------------------------------------------------------\n\n");
    printf("Kahvalti ve aksam yemekleri tercihlerinde 1 yemekli ,0 ise yemeksiz rezervasyonlardir.\nBu secim sistemdeki otomatik otel paketlerinden saglanmaktadir.\n\n");
    for(i=0; i<N; i++)
    {
        printf("*****************************************************\n");
        if(musteriler[i].kahvalti==1 && musteriler[i].aksamyemegi==1)
        {
            printf("%d. Musteri sabah kahvaltisi ve aksam yemegi olan otel paketinden yararlanmistir.\n",i+1);
        }
        else if(musteriler[i].kahvalti==1 && musteriler[i].aksamyemegi==0)
        {
            printf("%d. Musteri sabah kahvaltisi olan ve aksam yemegi olmayan otel paketinden yararlanmistir.\n",i+1);
        }
        else if(musteriler[i].kahvalti==0 && musteriler[i].aksamyemegi==1)
        {
            printf("%d. Musteri sabah kahvaltisi olmayan ve aksam yemegi olan otel paketinden yararlanmistir.\n",i+1);
        }
        else
        {
            printf("%d. Musteri sabah kahvaltisi ve aksam yemegi olmayan otel paketinden yararlanmistir.\n",i+1);
        }
    }
    printf("*****************************************************\n\n\n");



}
void musteriadsoyad(struct musteri musteriler[N])
{
    int i;
    for(i=0; i<N; i++)
    {
        printf("Musterilerin adi ve  soyadini giriniz:\n");
        scanf("%s %s",&musteriler[i].isim,&musteriler[i].soyisim);
    }
    printf("\n\n");

}
int main()
{
    printf("------------------------Otel Musteri Odemeleri------------------------\n");
    struct musteri musteriler[N];
    int kahvaltiucreti=200,aksamyemegiucreti=500;

    musteriadsoyad(musteriler);
    musteriyemektercihleri(musteriler,kahvaltiucreti,aksamyemegiucreti);
    oteltercihleri(musteriler);
    kisitercihleri(musteriler,kahvaltiucreti,aksamyemegiucreti);
    musteribilgilerinibastir(musteriler);
    maxucret(musteriler);
    return 0;
}
