#include <iostream>
#include <vector>
#include <string>
#include "datingApp.hpp"

using namespace std;

int main() {
    DatingApp* app = DatingApp::getInstance();
    vector<string> Users;

    cout << "\n===============< Welcome to Our Dating App >====================\n";

    while (true) {
        cout << "\n===============< Choose an Option >====================\n";
        cout << "1. Create New User\n";
        cout << "2. View User Profile\n";
        cout << "3. Search Nearby Users\n";
        cout << "4. Swipe (Match)\n";
        cout << "5. Chat Room\n";
        cout << "6. Exit\n";
        cout << "======================================================\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cin.ignore();

        string userId, name, gender, bio, addPhoto, interest, category, inter, uss1, uss2;
        int age, minAge, maxAge, maxDis;
        string us1, us2;

        switch (choice) {
        case 1: {
            cout << "\nEnter a new User ID: ";
            getline(cin, userId);
            if (find(Users.begin(), Users.end(), userId) != Users.end()) {
                cout << "User already exists!\n";
                break;
            }
            Users.push_back(userId);
            User* user = app->createUser(userId);

            UserProfile* profile = user->getProfile();
            cout << "Enter your name: ";
            getline(cin, name);
            profile->setName(name);

            cout << "Enter your age: ";
            cin >> age;
            profile->setAge(age);
            cin.ignore();

            cout << "Enter your gender (Male/Female/Other): ";
            getline(cin, gender);
            if (gender == "Male" || gender == "male")
                profile->setGender(Gender::MALE);
            else if (gender == "Female" || gender == "female")
                profile->setGender(Gender::FEMALE);
            else
                profile->setGender(Gender::OTHER);

            cout << "Enter a short bio: ";
            getline(cin, bio);
            profile->setBio(bio);

            cout << "Enter your photo filename: ";
            getline(cin, addPhoto);
            profile->addPhotos(addPhoto);

            cout << "Add your interests (type 'done' to finish):\n";
            while (true) {
                cout << "Interest name: ";
                getline(cin, interest);
                if (interest == "done") break;
                cout << "Category: ";
                getline(cin, category);
                profile->addIntreset(interest, category);
            }

            double lat, lon;
            cout << "Enter your location (latitude longitude): ";
            cin >> lat >> lon;
            cin.ignore();
            Location loc;
            loc.setLatitude(lat);
            loc.setLongitude(lon);
            profile->setLocation(loc);

            Preferences* pref = user->getPreference();
            cout << "\nAdd your preferences:\n";

            cout << "Interested in gender (Male/Female/Other): ";
            getline(cin, gender);
            if (gender == "Male" || gender == "male")
                pref->addGenderPreferences(Gender::MALE);
            else if (gender == "Female" || gender == "female")
                pref->addGenderPreferences(Gender::FEMALE);
            else
                pref->addGenderPreferences(Gender::OTHER);

            cout << "Enter preferred age range (min max): ";
            cin >> minAge >> maxAge;
            pref->setAgeRange(minAge, maxAge);

            cout << "Enter max distance (in km): ";
            cin >> maxDis;
            pref->setMaxDistance(maxDis);
            cin.ignore();

            cout << "Enter interests you prefer in others (type 'done' to finish):\n";
            while (true) {
                cout << "Interest: ";
                getline(cin, inter);
                if (inter == "done") break;
                pref->addInterested(inter);
            }

            cout << "\n✅ User created successfully!\n";
            break;
        }

        case 2: {
            cout << "Enter your user ID: ";
            getline(cin, userId);
            User* user = app->getUserById(userId);
            if (!user) {
                cout << "❌ User not found.\n";
                break;
            }
            cout << "\n======================< USER PROFILE >=========================\n";
            user->displayProfile();
            break;
        }

        case 3: {
            cout << "Enter your user ID: ";
            getline(cin, userId);
            cout << "Enter max distance (in km): ";
            cin >> maxDis;
            cin.ignore();
            vector<User*> nearUsers = app->findNearByUsers(userId, maxDis);

            cout << "\n----------- Nearby Users -----------\n";
            cout << "Found " << nearUsers.size() << " nearby users.\n";
            for (auto u : nearUsers) {
                cout << "- " << u->getProfile()->getName()
                     << " (" << u->getId() << ")\n";
            }
            break;
        }

        case 4: {
            cout << "Enter your user ID: ";
            getline(cin, us1);
            cout << "Enter the target user ID: ";
            getline(cin, us2);
            bool matched = app->swipe(us1, us2, SwipeAction::RIGHT);
            if (matched)
                cout << "🎉 You have a new match!\n";
            else
                cout << "Swipe recorded. Waiting for the other user...\n";
            break;
        }

        case 5: {
            cout <<"===Chat Room Create Do message====="<<endl;
            
            while (true)
            {
                cout << "Enter your user ID: ";
                getline(cin, us1);
                if(us1 == "done")
                break;
                uss1 = us1;
                cout << "Enter the other user ID: ";
                getline(cin, us2);
                uss2 = us2;
                string message;
                cout << "Enter your message: ";
                getline(cin, message);
                app->sendMessage(us1, us2, message);
            }            
            cout << "\n===============< Chat Room >===============\n";
            app->displayChatRoom(uss1, uss2);
            break;
        }

        case 6:
            cout << "Thank you for using our Dating App! ❤️\n";
            return 0;

        default:
            cout << "❌ Invalid option. Please try again.\n";
        }
    }

    return 0;
}
