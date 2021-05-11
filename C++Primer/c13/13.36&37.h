//
// Created by KujouRinka on 2021/5/11.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHM_13_36_H
#define DATA_STRUCTURES_AND_ALGORITHM_13_36_H

#include <string>
#include <set>

class Folder;

class Message;

class Folder {
public:
    Folder() = default;

    Folder(const Folder &rhs);

    Folder &operator=(const Folder &rhs);

    void addMsg(Message *msg);

    void remMsg(Message *msg);

    ~Folder();

private:
    void add_to_Messages(const Folder &f);

    void remove_from_Messages();

    std::set<Message *> messages;
};


class Message {
    friend class Folder;

    friend void swap(Message &lhs, Message &rhs);

public:
    explicit Message(const std::string &s = std::string()) :
            contents(s) {}

    Message(const Message &rhs);

    Message &operator=(const Message &rhs);

    void save(Folder &f);

    void remove(Folder &f);

    void addFldr(Folder *f);

    void remFldr(Folder *f);

    ~Message();

private:
    std::string contents;
    std::set<Folder *> folders;

    void add_to_Folders(const Message &msg);

    void remove_from_Folders();
};

#endif //DATA_STRUCTURES_AND_ALGORITHM_13_36_H
