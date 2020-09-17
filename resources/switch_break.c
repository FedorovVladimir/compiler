//
//  switch_break.c
//  
//
//  Created by Maxim Butin on 17.09.2020.
//

int main() {

    double num1, num2;
    char operation, redo;
    while (redo != y) {
        //----receiving the variables from input--------------
        print("Please enter an operation which you like to calculate (+,-,*,/,s)");
        print("[s stands for swap]:");
        cin(operation);
        print("\n\n");
        print("Please enter two numbers to apply your requested operation(");
        print(operation + "):\n1st num:");
        cin(num1);
        print("2nd num:");
        cin(num2);
        print("\n");

        //---used switch function so thet the operater can be decided------------
        switch (operation) {
            //------calculating the requested equation for inputs-------------
            //-------at the same time printing the results on screen-----------
            case '+':
                print("The addition of two numbers (" + num1 + "," + num2 + "):");
                print(num1 + num2 + "\n");
                break;
            case '-':
                print("The substraction of two numbers (" + num1 + "," + num2 + "):");
                print(num1 - num2 + "\n");
                break;
            case '*':
                print("The multiplication of two numbers (" + num1 + "," + num2 + "):");
                print(num1 * num2 + "\n");
                break;
            case '/':
                print("The division of two numbers (" + num1 + "," + num2 + "):");
                if (num2 == 0) {
                    print("not valid\n");
                }
                print((num1 / num2) + "\n");
                break;
            case 's':
                print("The swap of two numbers (" + num1 + "," + num2 + "):");
                swap(num1, num2);
                print("1stnumber=" + num1 + "and 2nd number=" + num2 + "\n\n");
                break;
            default:
                print("unknown command\n");

        }
        //----now once again the program will ask the user if want to continue or not
        print("enter y or Y to continue:");
        cin(redo);
        print("\n\n");
    }

    return 0;
}
