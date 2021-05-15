#include <iostream>
#include <utility>
#include <string>
#include <set>
#include "13.36&37.h"

Folder::Folder(const Folder &rhs) :
        messages(rhs.messages) {
    add_to_Messages(rhs);
}

Folder &Folder::operator=(const Folder &rhs) {
    remove_from_Messages();
    messages = rhs.messages;
    add_to_Messages(*this);
    return *this;
}

Folder::~Folder() {
    remove_from_Messages();
}

void Folder::addMsg(Message *msg) {
    messages.insert(msg);
}

void Folder::remMsg(Message *msg) {
    messages.erase(msg);
}

void Folder::add_to_Messages(const Folder &f) {
    for (auto &msg : f.messages)
        msg->addFldr(this);
}

void Folder::remove_from_Messages() {
    while (!messages.empty())
        (*messages.begin())->remove(*this);
}

// --------------------------------------------------------
Message::Message(const Message &rhs) :
        contents(rhs.contents), folders(rhs.folders) {
    add_to_Folders(rhs);
}

Message::Message(Message &&rhs) : contents(std::move(rhs.contents)) {
    move_Folders(&rhs);
}

Message &Message::operator=(const Message &rhs) {
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(*this);
    return *this;
}

Message &Message::operator=(Message &&rhs) {
    if (this != &rhs) {
        remove_from_Folders();
        contents = std::move(rhs.contents);
        move_Folders(&rhs);
    }
    return *this;
}

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

void Message::addFldr(Folder *f) {
    folders.insert(f);
}

void Message::remFldr(Folder *f) {
    folders.erase(f);
}

void Message::add_to_Folders(const Message &msg) {
    for (auto &f : msg.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders() {
    for (auto &f : folders)
        f->remMsg(this);
}

void Message::move_Folders(Message *msg) {
    folders = std::move(msg->folders);
    for (auto &f : folders) {
        f->remMsg(msg);
        f->addMsg(this);
    }
    msg->folders.clear();
}

Message::~Message() {
    remove_from_Folders();
}

void swap(Message &lhs, Message &rhs) {
    lhs.remove_from_Folders();
    rhs.remove_from_Folders();
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    lhs.add_to_Folders(lhs);
    rhs.add_to_Folders(rhs);
}
