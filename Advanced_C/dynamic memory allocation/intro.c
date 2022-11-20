
    int N, *p, i;
    printf("N:\n");
    scanf("%d", &N);

    p = (int *) malloc(N* sizeof(int));

    if(p == NULL)
    {
        fprintf(stderr, "Memory allocation error!");
        exit(EXIT_FAILURE);
    }

    else
    {
        for(i = 0; i < N; i++)
        {
            printf("%d. number:\n", i+1);
            scanf("%d", &p[i]);
        }
        printf("successfully added to the array!\n");

        for(i = 0; i < N; i++, p++)
        {
            printf("%d\t", *p);
        }
    }