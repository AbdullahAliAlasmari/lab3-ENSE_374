    /*

     * C++ Program to Implement Doubly Linked List 

     */

    #include<iostream>

    #include<cstdio>

    #include<cstdlib>

    /*

     * Node Declaration

     */

    using namespace std;

    struct node{

        int data;
        struct node *next;
        struct node *prev;
    }*head;

     

    /*

     Class Declaration 

     */

    class double_LinkedlList

    {

        public:

            void create_ListElement(int index); // Create Double Link List

            void Add_Element_At_The_begining_Of_The_list(int index); //Adds an element at the beginning of the list.

            void Add_Element_At_The_End_Of_The_list(int Element_Val, int location);// Adds an element at the end of the list.

            void deleteElement(int index); //Deletion of element from the list

            void printLinkedListHead();//Displays the complete list in a forward manner.

            void printLinkedListTail();// Displays the complete list in a backward manner.

            double_LinkedlList() // structure 

            {

                head = NULL;  

            }

    };

     

    /*

     * Main function

     */

    int main()

    {

        int choice, element, position;

        double_LinkedlList dl;

        while (1)

        {

            

            cout<<endl<<" A Doubly Linked List Program that has the following requirements."<<endl;

               

            cout<<"1.Create Node"<<endl;

            cout<<"2.Adding a node at the begining of the list "<<endl;

            cout<<"3.Adding a node at the end of the list  "<<endl;

            cout<<"4.Delete a node from anywhere of the list"<<endl;

            cout<<"5.Display the list "<<endl;

            cout<<"6. Display the list but in Reverse"<<endl;

            cout<<"7.Exit the program"<<endl;

            cout<<"Enter your choice : ";

            cin>>choice;

            switch ( choice )

            {

            case 1:

                cout<<"Enter the element: ";

                cin>>element;

                dl.create_ListElement(element);

                cout<<endl;

                break;

            case 2:

                cout<<"Enter the element: ";

                cin>>element;

                dl.Add_Element_At_The_begining_Of_The_list(element);

                cout<<endl;

                break;

            case 3:

                cout<<"Enter the element: ";

                cin>>element;

                cout<<" Adding a node at the end of the list ";

                cin>>position;

                dl.Add_Element_At_The_End_Of_The_list(element, position);

                cout<<endl;

                break;

            case 4:

                if (head == NULL)

                {                      

                    cout<<"List is empty"<<endl;   

                    break;

                }

                cout<<"Enter the element you want to delete: ";

                cin>>element;

                dl.deleteElement(element);

                cout<<endl;

                break;

            case 6:

                if (head == NULL)

                {

                    cout<<"List is empty"<<endl;

                    break;

                }

                dl.printLinkedListTail();

                cout<<endl;

                break;

            case 7:

                exit(1);

            default:

                cout<<" choise should be between 0 and 8 "<<endl;

            }

        }

        return 0;

    }

     

    /*

     * Create Double Link List

     */

    void double_LinkedlList::create_ListElement(int index)

    {

        struct node *s, *temp;

        temp = new(struct node); 

        temp->data = index;

        temp->next = NULL;

        if (head == NULL)

        {

            temp->prev = NULL;

            head = temp;

        }

        else

        {

            s = head;

            while (s->next != NULL)

                s = s->next;

            s->next = temp;

            temp->prev = s;

        }

    }

     

    /*

     * Insertion at the beginning

     */

    void double_LinkedlList::Add_Element_At_The_begining_Of_The_list(int index)

    {

        if (head == NULL)

        {

            cout<<"You must Create the first node in the list."<<endl;

            return;

        }

        struct node *temp;

        temp = new(struct node);

        temp->prev = NULL;

        temp->data = index;

        temp->next = head;

        head->prev = temp;

        head = temp;

        cout<<"Element Inserted"<<endl;

    }

     

    /*

     * Insertion of element at a particular position

     */

    void double_LinkedlList::Add_Element_At_The_End_Of_The_list(int Element_V, int loc)

    {

        if (head == NULL)

        {

            cout<<"You must Create the first node in the list."<<endl;

            return;

        }

        struct node *tmp, *q;

        int i;

        q = head;

        for (i = 0;i < loc - 1;i++)

        {

            q = q->next;

            if (q == NULL)

            {

                cout<<"There are less than ";

                cout<<loc<<" elements in the list ."<<endl;

                return;

            }

        }

        tmp = new(struct node);

        tmp->data = Element_V;

        if (q->next == NULL)

        {

            q->next = tmp;

            tmp->next = NULL;

            tmp->prev = q;      

        }

        else

        {

            tmp->next = q->next;

            tmp->next->prev = tmp;

            q->next = tmp;

            tmp->prev = q;

        }

        cout<<"Element Inserted"<<endl;

    }

     

    /*

     * Deletion of element from the list

     */

    void double_LinkedlList::deleteElement(int index)

    {

        struct node *tmp, *q;

         /*first element deletion*/

        if (head->data == index)

        {

            tmp = head;

            head = head->next;  

            head->prev = NULL;

            cout<<"First Element Deleted"<<endl;

            free(tmp);

            return;

        }

        q = head;

        while (q->next->next != NULL)

        {   

            /*Element deleted in between*/

            if (q->next->data == index)  

            {

                tmp = q->next;

                q->next = tmp->next;

                tmp->next->prev = q;

                cout<<"Element deleted in between"<<endl;

                free(tmp);

                return;

            }

            q = q->next;

        }

         /*last element deleted*/

        if (q->next->data == index)    

        { 	

            tmp = q->next;

            free(tmp);

            q->next = NULL;

            cout<<"Last Element Deleted"<<endl;

            return;

        }

        cout<<" the Element "<<index<<" not found"<<endl;

    }

     

    /*

     * Display elements of Doubly Link List

     */

    void double_LinkedlList::printLinkedListHead()

    {

        struct node *q;

        if (head == NULL)

        {

            cout<<"List is empty"<<endl;

            return;

        }

        q = head;

        cout<<"The Doubly Link List is :"<<endl;

        while (q != NULL)

        {

            cout<<q->data<<" <-> ";

            q = q->next;

        }

        cout<<"NULL"<<endl;

    }

     

    

    /*

     * Reverse Doubly Link List

     */

    void double_LinkedlList::printLinkedListTail()

    {

        struct node *p1, *p2;

        p1 = head;

        p2 = p1->next;

        p1->next = NULL;

        p1->prev = p2;

        while (p2 != NULL)

        {

            p2->prev = p2->next;

            p2->next = p1;

            p1 = p2;

            p2 = p2->prev; 

        }

        head = p1;

        cout<<"List Reversed"<<endl; 

    }