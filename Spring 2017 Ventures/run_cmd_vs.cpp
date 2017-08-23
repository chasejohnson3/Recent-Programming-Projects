// Programmer: Chase Johnson
// Date: 1/30/17
// File Homework2
// Description: A thrilling story adventure to test my if statement skills

#include<iostream>

using namespace std;

int main(void)
{
    //initialize numbers and booleans
    int decision1, decision2, decision3, decision4, decision5, decision6, valor_points(0);
    bool play_again(false), has_mystical_plant(false), dragon_slain(false), user_still_alive(true), still_on_adventure(true);
    // incorrect_response1 is used for the location of the goto if the user inputs an integer not 1 through 4
    incorrect_response1:
    // This is the first decision for the user.
    cout << "A long time ago in a land far far away lived a prince.\n"
    "This prince heard of a fair princess locked away in a tower \n"
    "guarded by a massive fire-breathing dragon.  She needs rescuing. \n\n"
    "What do you do? \n"
    "1) Gear up to fight the dragon and rescue the princess. \n"
    "2) Hire Shrek to do it.\n"
    "3) Chicken out because you'll probably die. \n"
    "4) Bring a friend to attack the monster. \n"
    "Your decision: ";
    cin >> decision1;

    switch (decision1)
    {
        case 1: valor_points += 50;
            cout << "\nA bold decision. Respectable.\n" << endl;
            break;
        case 2:
            valor_points -= 10;
            cout << "\nThe princess is saved in valiant effort by Shrek, but you are deemed a weenie.\n" << endl;
            dragon_slain = true;
            still_on_adventure = false;
            break;
        case 3:
            valor_points -= 50;
            cout << "\nYou are a terrible person.  The princess is stranded and you have no guts.\n" << endl;
            still_on_adventure = false;
            dragon_slain = false;
            break;
        case 4: valor_points += 25;
            cout << "\nAlthough you require a security blanket, your decision is admirable.\n";
            break;
        default:
            cout << "\nYou have not entered a valid response. Try again...\n" << endl;
            goto incorrect_response1;
            break;
    }

    // If the user decides to go on the adventure, we move to this next question
    if (still_on_adventure && user_still_alive)
    {
        // asks the question again if the user input was not 1,2,3, or 4.
        incorrect_response2:
        cout << "Before you begin, you will need armor.\n"
                "How will you obtain this armor?\n"
                "1) Steal it from the local merchant.\n"
                "2) Purchase it from the best blacksmith in the land.\n"
                "3) Go cheap to save money and still have armor.\n"
                "4) Don't obtain armor.  Real men don't use armor.\n"
                "Your decision: ";
        cin >> decision2;
        switch (decision2)
        {
            case 1:
                valor_points -= 15;
                break;
            case 2:
                valor_points +=10;
                break;
            case 3:
                valor_points +=10;
                break;
            case 4:
                valor_points +=15;
                break;
            default:
                cout << "\nYou have not entered a valid response. Try again...\n" << endl;
                goto incorrect_response2;
                break;
        }
    }

    // This plant may help in the adventure later.  It does not contribute any valor points.
    if (still_on_adventure && user_still_alive)
    {
        incorrect_response3:
        cout << "\nWhile running toward the castle, you see a mystical plant.  Do you pick it up?\n"
                "1) Yes\n"
                "2) No\n"
                "Your decision: ";
        cin >> decision3;
        if (decision3 == 1)
        {
            has_mystical_plant = true;
        }
        else if (decision3 ==2)
        {
            has_mystical_plant = false;
        }
        else
        {
            cout << "\nYou have not entered a valid response. Try again...\n" << endl;
            goto incorrect_response3;
        }
    }

    // asks the question again if the user input was not 1,2,3, or 4.
    incorrect_response4:
    if (still_on_adventure && user_still_alive)
    {
        cout << "\nAs you approach the castle, you see the dragon's imposing figure outlined\n"
                "by the blood red sunset.  Heart racing, you must climb to the highest tower\n"
                "to find the princess.  However, the dragon interrupts your path.\n"
                "What move do you use?\n"
                "1) Run away.\n"
                "2) Team facade double attack.\n"
                "3) Sword power drive.\n"
                "4) Tackle it with your bare hands.\n"
                "Your decision: ";
        cin >> decision4;
        switch (decision4)
        {
            case 1:
                valor_points -= 30;
                cout << "\nYou have dishonored your family and nation.\n";
                break;
            case 2:
                // this only works if you brought a friend from decision 1.
                if (decision1 == 4)
                {
                    valor_points += 50;
                    cout << "\nYou have slain the dragon with the help of your friend.  I commend your teamwork.\n";
                    dragon_slain = true;
                }
                else
                {
                    cout << "\nYou have no partner with whom to complete this move.  You are dead.\n";
                    user_still_alive = false;
                }
                break;
            case 3:
                // this only works if you obtained armor in decision 2.
                if (decision2==1 || decision2==2 || decision2==3)
                {
                    valor_points +=50;
                    cout << "\nYou have slain the dragon, congratulations.\n";
                    dragon_slain = true;
                }
                else
                {
                    cout << "\nYou had no armor to attack the dragon and died.\n";
                    user_still_alive = false;
                }
                break;
            case 4:
                incorrect_response5:
                cout << "\nSomehow you manage to slay the dragon, but you experience fatal wounds.\n";
                valor_points += 50;
                dragon_slain = true;
                // The fatal wounds must be dealt with or you do not live
                cout << "\nWhat will you do to remedy your wound?\n"
                        "1) Walk it off and hope it heals.\n"
                        "2) Run to the nearest medic.\n"
                        "3) Eat the mystical plant.\n"
                        "4) Moan \"WHY IS LIFE SO HARD???\"\n"
                        "Your decision: ";
                cin >> decision5;
                switch (decision5)
                {
                    case 1:
                        cout << "\nThis was a useless act.  You die walking.\n";
                        user_still_alive = false;
                        break;
                    case 2:
                        cout << "\nYou don't make it to the medic.  You die running.\n";
                        user_still_alive = false;
                        break;
                    case 3:
                        if (has_mystical_plant)
                        {
                            cout << "\nThe mystical plant magically heals your fatal wound!\n";
                            user_still_alive = true;
                            break;
                        }
                        else
                        {
                            cout << "\nYou did not pick up the mystical plant, so you cannot eat it.\n"
                                    "You died of the fatal wound.\n";
                            user_still_alive = false;
                            break;
                        }
                    case 4:
                        cout << "\nYou died. 'nuff said.\n";
                        user_still_alive = false;
                        break;
                    default:
                        cout << "\nYou have not entered a valid response. Try again...\n" << endl;
                        goto incorrect_response5;
                        break;
                }
                break;
            default:
                cout << "\nYou have not entered a valid response. Try again...\n" << endl;
                goto incorrect_response4;
                break;
        }
    }
    // The user has decided not to continue the adventure.
    else
    {
        cout << "\nYour adventure is over.  I thought better of you.\n";
    }

    incorrect_response6:
    if (still_on_adventure && user_still_alive && (decision4==2 || decision4==3 || decision4==4))
        {
            cout << "\nYou climb to the tallest tower and find the princess.\n"
                    "Carrying her down the stairs, you successfully rescue her.\n"
                    "How do you get her home?\n"
                    "1) Carry her all the way home.\n"
                    "2) Allow her to ride your horse home.\n"
                    "3) Make her walk.\n"
                    "4) Make her carry you.\n"
                    "Your decision: ";
            cin >> decision6;
            switch (decision6)
            {
                case 1:
                    valor_points += 75;
                    break;
                case 2:
                    valor_points += 50;
                    break;
                case 3:
                    valor_points -= 25;
                    break;
                case 4:
                    valor_points -= 75;
                    break;
                default:
                    cout << "\nYou have not entered a valid response. Try again...\n" << endl;
                    goto incorrect_response6;
                    break;
            }
        }

    // assesses the adventure by how many valor points you gained, if you survived, and if you killed the dragon
    cout << "\nThroughout your adventure, you earned " << valor_points << " valor points.\n" << endl;
    if (valor_points<0)
    {
        cout << "\nAs evident by your valor points, your adventure was pitiful,";
        if (dragon_slain)
        {
            cout << "but at least you killed the dragon to rescue the princess.";
        }
        else{
            cout << "and you didn't even manage to kill the dragon.";
        }
    }
    else if (valor_points<50)
    {
        cout << "As evident by your valor points, your adventure wasn't very good.\n";
    }
    else if (valor_points<100)
    {
        cout << "As evident by your valor points, your adventure was good.\n";
    }
    else if (valor_points<150)
    {
        cout << "As evident by your valor points, your adventure was great.\n";
    }
    else
    {
        cout << "As evident by your valor points, your adventure was outstanding!\n";
    }

    if (user_still_alive)
    {
        cout << "\nIn other news, you stayed alive!\n";
    }
    else
    {
        cout << "On the other hand, you are dead, so it doesn't really matter how many valor points you got.\n";
    }
    cout << "\nWould you like to play again? (0/1)" << endl;
    cin >> play_again;

    // allows the user to play again if they input 1.  Then, the code resets the default booleans and uses a lot of line breaks
    // to make it look like a blank screen with a new story.
    if(play_again)
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        valor_points = 0;
        dragon_slain = false;
        user_still_alive = true;
        still_on_adventure = true;
        goto incorrect_response1;
    }
}
