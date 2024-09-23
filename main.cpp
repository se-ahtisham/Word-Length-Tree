
#include"bst.h"



void intro()
{

    cout << " \t\t***************************************************************" << endl;
    cout << " \t\t>>>         Binary Search Tree Word Game        <<<" << endl;
    cout << " \t\t***************************************************************" << endl;
    cout << endl;
}



int main()
{
    intro();
    int choice = 1;
    BinarySearchTree b1;
    while (choice != 0)
    {
        int mainchoice = 0;
        cout << endl;
        cout << " Press 1. For Insert Paragraph " << endl;
        cout << " Press 2. For Search Word " << endl;
        cout << " Press 3. For Delete Word " << endl;
        cout << " Press 4. For Print Pre Order Format " << endl;
        cout << " Press 5. For Print In Order Format" << endl;
        cout << " Press 6. For Print Post Order Format " << endl;
        cout << " Press 7. For Find Height " << endl;
        cout << " Press 8. For Find Shortest Word " << endl;
        cout << " Press 9. For Find Largest Word " << endl;
        cout << " Please Enter Your Choice >>>> ";
        cin >> mainchoice;
        switch (mainchoice)
        {
        case 1:
        {
            cout << endl;
            char paragraph[1000];
            cout << "Enter a paragraph: ";
            cin.ignore();  // Ignore the newline character left in the buffer
            cin.getline(paragraph, sizeof(paragraph));

            char* word = nullptr;
            char* nextToken = nullptr;
            word = strtok_s(paragraph, " ,.?!;:", &nextToken);
            while (word != NULL) {
                b1.Insert(word);
                word = strtok_s(nullptr, " ,.?!;:", &nextToken);
            }
            cout << endl;
        }
        break;
        case 2:
        {
            cout << endl;
            string name;
            cout << " Please Enter Word: ";
            cin >> name;
            b1.Search(name);
            cout << endl;
        }
        break;

        case 3:
        {
            cout << endl;
            string name;
            cout << " Please Enter Word: ";
            cin >> name;
            b1.Delete(name);
            cout << endl;
        }
        break;

        case 4:
        {
            cout << endl;
            b1.PreorderPrint(b1.getroot());
            cout << endl;
        }
        break;

        case 5:
        {
            cout << endl;
            b1.InorderPrint(b1.getroot());
            cout << endl;
        }
        break;

        case 6:
        {
            cout << endl;
            b1.PostorderPrint(b1.getroot());
            cout << endl;
        }
        break;

        case 7:
        {
            cout << endl;
            b1.FindHeight();
            cout << endl;
        }
        break;

        case 8:
        {
            cout << endl;
            b1.FindShortestword();
            cout << endl;
        }
        break;

        case 9:
        {
            cout << endl;
            b1.Findmaximumword();
            cout << endl;
        }
        break;



        default:
        {
            cout << " Error! Invalid Input:( " << endl;
        }
        break;
        }
        cout << endl;
        cout << " Press Any key to continous and 0 For Exit" << endl;
        cout << " Please Enter your choice: ";
        cin >> choice;
    }

   
    system("pause");
}