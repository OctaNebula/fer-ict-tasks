unsigned short kodiraj(int smjer, int koraci, int kamera, int svjetla, int hitno)
{
    unsigned short result = 0;
    return result;
}

int main()
{
    printf("Upisite vrijednosti > ");
    int smjer, koraci, kamera, svjetla, hitno;
    scanf("%d%d%d%d", &smjer, &koraci, &kamera, &hitno);
    printf("%hu", kodiraj(smjer, koraci, kamera, svjetla, hitno));
    return 0;
}