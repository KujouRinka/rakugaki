def load_data_set():
    posting_list = [
        ['my', 'dog', 'has', 'flea',
         'problems', 'help', 'please'],
        ['maybe', 'not', 'take', 'him',
         'to', 'dog', 'park', 'stupid'],
        ['my', 'dalmation', 'is', 'so', 'cute',
         'I', 'love', 'him'],
        ['stop', 'posting', 'stupid', 'worthless', 'garbage'],
        ['mr', 'licks', 'ate', 'my', 'steak', 'how',
         'to', 'stop', 'him'],
        ['quit', 'buying', 'worthless', 'dog', 'food', 'stupid']
    ]
    class_vec = [0, 1, 0, 1, 0, 1]
    return posting_list, class_vec


def create_vocab_list(data_set):
    vocab_set = set()
    for document in data_set:
        vocab_set = vocab_set | set(document)
    return list(vocab_set)


def set_of_words2vec(vocab_list, input_set):
    return_vec = [0] * len(vocab_list)
    for word in input_set:
        try:
            return_vec[vocab_list.index(word)] = 1
        except ValueError:
            print('the word: {} is not in vocabulary'.format(word))
    return return_vec


def main():
    list_o_posts, list_classes = load_data_set()
    my_vocab_list = create_vocab_list(list_o_posts)
    print(my_vocab_list)
    print(set_of_words2vec(my_vocab_list, list_o_posts[0]))


if __name__ == '__main__':
    main()
