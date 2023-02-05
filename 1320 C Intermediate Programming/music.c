typedef	struct	_Node
{
    char *singer_name;
    int *albums_sold;
    int number_tour_cities;
    char** tour_cities_name;
    struct node	*left;
    struct node *right;
}Node;
void read_file(char filename)
{
    FILE* fp = fopen(filename, "r");
    char* token;
    char line[50];
    Node* temp = NULL;
    Node* head = NULL;

    while(fgets(line,100,fp))
    {    
        token = strtok(line, ",");
        temp = malloc(sizeof(Node));
        temp->singer_name = malloc(25);
        strcpy(temp->singer_name, token);
        
        token = strtok(NULL, ",");
        temp->albums_sold = malloc(sizeof(int));
        temp->albums_sold = atoi(token);

        token = strtok(NULL, ",");
        temp->number_tour_cities = atoi(token);

        token = strtok(NULL, ",\n");
        temp->tour_cities_name = malloc(sizeof(char)*3);
        strcpy(temp->tour_cities_name[0],token);

        token = strtok(NULL, ",\n");
        strcpy(temp->tour_cities_name[1],token);

        token = strtok(NULL, ",\n");
        strcpy(temp->tour_cities_name[2],token);

        if(temp->albums_sold<=100)
        {    
            temp->left = head;
            head = temp;
        }

        else if(temp->albums_sold>=100)
        {
            temp->right = head;
            head = temp;
        }
    }
}