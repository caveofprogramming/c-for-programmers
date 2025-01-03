  struct Person 
    {
        int id;
        float height;
    };

    struct Person bob = {22, 1.82f};

    bob.id = 21;
    bob.height = 1.78;

    printf("Bob: %d, %.1f\n", bob.id, bob.height);

    struct Values
    {
        int id;
    } v1={2}, v2={3};

    printf("v1: %d\n", v1.id);
    printf("v2: %d\n", v2.id);

      struct Person 
    {
        int id;
        float height;
    };

    struct Person bob = {22, 1.82f};

    bob = (struct Person){.id=23, .height=1.80f};

    bob.id = 21;
    bob.height = 1.78;
    

    printf("Bob: %d, %.1f\n", bob.id, bob.height);

    return 0;