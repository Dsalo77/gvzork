#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <exception>

#include "item.h"
#include "location.hpp"
#include "npc.hpp"
#include "direction.h"

typedef void (&Command)(std::vector<std::string>);


using namespace std;



class Game {
        private:
                map<string, Command> commands = {};
                std::vector<Item> playerItems = {};
                int inventoryWeight = 0;
                std::vector<Location> locationsThatExistInTheWorld = {};
                Location currentLocation;
                int caloriesFedToTheElf = 0;
                bool gameStillInProgress = true, ateTheMRE = false, drankCoffee = false;

        public:
                Game();
                void doSetup();
                map<string, Item> itemSetup();
                map<string, NPC> NPCSetup();
                void locationSetup(map<string, NPC> npcList, map<string, Item> itemList);

                // adding needed methods
                //void show_help();
                //void talk(target);
                //void meet(std::vector<std::string> target);
                //void take(vector<string> target);
                //void give(vector<string> target);
                //void go(vector<string> target);
                //void show_items(vector<string> target);
                //void look(vector<string> target);
                //void quit(vector<string> target);

};

//May as well just do setup here
Game::Game()
{

        //this->woodring = NPC("Prof Woodring", "He's the CS prof from North Carolina");
        // NPC woodring("Prof. Woodring", "He's the CS prof from North Carolina", {"How do you do?", "Something something something"});
        // cout << woodring << endl;
        // Location l("The woods", "it's the woods");
        // //cout << l << endl;
        // Item i("Piece of shit", "it's a dog turd");
        // cout << i << endl;
        // currentLocation = l;
        // cout << currentLocation << endl;

        //locationsThatExistInTheWorld.push_back(l);




        doSetup();

}

void Game::doSetup() {
        //woodring = NPC("Prof. Woodring", "The Computer Science Professor");
        //Items
        map<string, Item> inGameItems = itemSetup();
        cout << inGameItems.at("Granolabar") << endl;
        cout << inGameItems.at("Banana") << endl;
        cout << inGameItems.at("Cake") << endl;
        cout << inGameItems.at("Green Herb") << endl;
        cout << inGameItems.at("Mushroom") << endl;
        cout << inGameItems.at("Sword") << endl;
        cout << inGameItems.at("Rock") << endl;
        cout << inGameItems.at("Ambrosia") << endl; //8
        cout << inGameItems.at("Relic") << endl;
        cout << inGameItems.at("Water") << endl; //10
        //NPC
        map<string, NPC> npcs = NPCSetup();
        cout << npcs.at("NPC1") << endl;
        cout << npcs.at("NPC2") << endl;
        cout << npcs.at("NPC3") << endl;
        cout << npcs.at("NPC4") << endl;
        cout << npcs.at("NPC5") << endl;

        locationSetup(npcs, inGameItems);

}

map<string, Item> Game::itemSetup() {
        map<string, Item> inGameItems = {};

        inGameItems.insert({"Banana", Item("Banana", "The fruit that's slightly shaped like a gun. Dispose of peels responsibly", 3, 0.9)});
        //cout << inGameItems.at("Banana") << endl;;
        inGameItems.insert({"Granolabar", Item("Granola bar", "Dry AF, nutritionally questionable, a good snack to give to someone else", 5, 0.1)});
        inGameItems.insert({"Cake", Item("Cake", "The cake is a lie", 300, 5)});
        inGameItems.insert({"Green Herb", Item("Green Herb", "Grown locally in Raccoon City", 10, 0.3)});
        inGameItems.insert({"Mushroom", Item("Mushroom", "May make you Super", 100, 1)});
        inGameItems.insert({"Sword", Item("Master Sword", "Super sharp", 0, 15)});
        inGameItems.insert({"Rock", Item("Rock", "Its not just a boulder Its a rock", 0, 10)});
        inGameItems.insert({"Ambrosia", Item("Ambrosia", "Consumed by the Gods", 400, 1)});
        inGameItems.insert({"Relic", Item("Holy Relic", "It belongs in a museum", 0, 25)});
        inGameItems.insert({"Water", Item("Water", "Needed for life", 0, 0.5)});
        return inGameItems;
}

map<string, NPC> Game::NPCSetup() {
        map<string, NPC> npcList = {};
        //add 5
        npcList.insert({"NPC1", NPC("Fisherman","Just fishing by the lake",{"How do you do? ",
                        "Some say there an old house just north of here. "," who knows what you could find there. "
                        "Well be seeing you. "})});
        npcList.insert({"NPC2", NPC("Hunter","Wearing a bright orange shirt vest", {"Hello", "You looked lost",
        "heading south will get you back to the road", "Goodbye" })});
        npcList.insert({"NPC3", NPC("Faceless Entity","Lurks in the shadows",{"Why have you come here? ",
                        "There is nothing here for you! ", "Leave this place!! "})});
        npcList.insert({"NPC4", NPC("","nope",{"Leave me", "get out of here"})});
        npcList.insert({"NPC5", NPC("NPC5","Tall",{"sup", "How it going"})});
        return npcList;
}

void Game::locationSetup(map<string, NPC> npcList, map<string, Item> itemList) {
        // Create and add locations to the game world
        Location forest("The Forest", "A dense forest with tall trees.");
        Location cave("Dark Cave", "A deep, dark cave with mysterious echoes.");
        Location river("River", "A deep river.");
        Location house("Old house", "An old falling apart house");
        Location tree("Golden tree", "A stunning Golden Tree");
        Location road("CrossRoads", "Many ways to go from here");
        Location hills("Hills", "Grassy hills");
        Location lake("lake", "A crystal clear lake");

        // Add locations to the vector
        locationsThatExistInTheWorld.push_back(forest);
        locationsThatExistInTheWorld.push_back(cave);
        locationsThatExistInTheWorld.push_back(river);
        locationsThatExistInTheWorld.push_back(house);
        locationsThatExistInTheWorld.push_back(tree);
        locationsThatExistInTheWorld.push_back(road);
        locationsThatExistInTheWorld.push_back(hills);
        locationsThatExistInTheWorld.push_back(lake);

        // Add items to forest
        forest.addItem(itemList.at("Banana"));
        forest.addNPC(npcList.at("NPC2"));

        //Add items to cave
        cave.addItem(itemList.at("Rock"));
        cave.addItem(itemList.at("Mushroom"));
        cave.addItem(itemList.at("Relic"));
        cave.addNPC(npcList.at("NPC4"));

        //add npc's and items to lake
        lake.addNPC(npcList.at("NPC1"));
        lake.addItem(itemList.at("Water"));

        //add to river
        river.addItem(itemList.at("Rock"));
        river.addItem(itemList.at("Water"));

        //add to house
        house.addItem(itemList.at("Cake"));
        house.addItem(itemList.at("Granolabar"));
        house.addNPC(npcList.at("NPC3"));

        //add to tree
        tree.addItem(itemList.at("Ambrosia"));
        tree.addItem(itemList.at("Sword"));
        tree.addNPC(npcList.at("NPC5"));


        //here to test if location was added to game world
        currentLocation = forest;
        cout << currentLocation << endl;
        currentLocation = lake;
        cout << currentLocation << endl;
        currentLocation = river;
        cout << currentLocation << endl;
        currentLocation = house;
        cout << currentLocation << endl;
        currentLocation = cave;
        cout << currentLocation << endl;
        currentLocation = tree;
        cout << currentLocation << endl;
}
