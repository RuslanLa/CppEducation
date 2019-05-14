#include <string>
#include <queue>
#include <iostream>

/*
 * Animal Shelter: An animal shelter, which holds only dogs and cats, operates on a strictly"first in, first out" basis.
 * People must adopt either the "oldest" (based on arrival time) of all animals at the shelter, or they can select whether they would prefer a dog or a cat
 * and will receive the oldest animal of that type). They cannot select which specific animal they would like.
 * Create the data structures to maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog, and dequeueCat.
 * You may use the built-in Linkedlist data structure
 * */

class Animal {
private:
    int Order;
public:
    Animal(int order, std::string&& name):Name(std::move(name)), Order(order){}
    std::string Name;
    bool isOlderThan(const Animal& animal) const {
        return this->Order < animal.Order;
    }
};


Animal pop(std::queue<Animal>& queue){
    Animal value = queue.front();
    queue.pop();
    return value;
}

std::ostream& operator << (std::ostream& os, const Animal& animal){
    os << animal.Name;
    return os;
}

class AnimalShelter {
private:
    std::queue<Animal> Cats;
    std::queue<Animal> Dogs;
    int lastIssuedOrder = 0;
    bool isCatOlderThanDog(){
        return Dogs.front().isOlderThan(Cats.front());
    }
    void enqueueAnimal(std::string&& name, std::queue<Animal>& queue){
        queue.push(Animal(lastIssuedOrder, std::move(name)));
        ++lastIssuedOrder;
    }
public:
    void enqueueCat(std::string cat){
        enqueueAnimal(std::move(cat), Cats);
    }

    void enqueueDog(std::string dog){
        enqueueAnimal(std::move(dog), Dogs);
    }

    Animal dequeueCat(){
        return pop(Cats);
    }

    Animal dequeueDog(){
        return pop(Dogs);

    }

    Animal dequeueAny(){
        auto* queueToPop = &Cats;
        if(!Dogs.empty()&& (Cats.empty() || isCatOlderThanDog())){
            queueToPop = &Dogs;
        }

        return pop(*queueToPop);
    }

};

int main(){
    AnimalShelter shelter {};
    shelter.enqueueCat("Cat1");
    shelter.enqueueDog("Dog1");
    std::cout << "dequeue 1 " << shelter.dequeueDog() << std::endl;
    shelter.enqueueDog("Dog2");
    std::cout << "dequeue 2 " << shelter.dequeueAny() << std::endl;
    shelter.enqueueCat("Cat2");
    shelter.enqueueDog("Dog3");
    std::cout << "dequeue 3 " << shelter.dequeueAny() << std::endl;
    std::cout << "dequeue 4 " << shelter.dequeueAny() << std::endl;
    std::cout << "dequeue 5 " << shelter.dequeueAny() << std::endl;
}