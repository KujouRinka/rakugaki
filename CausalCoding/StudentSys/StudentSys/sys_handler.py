import os
import re
import json
import pymysql
from abc import ABC, abstractmethod


class SysBaseHandler(ABC):
    """
    This is a abstract class which restrict methods
    a Handler must have.
    Some method that subclasses use have also included.
    """

    def __init__(self, sys):
        self._sys = sys

    @abstractmethod
    def insert(self):
        pass

    @abstractmethod
    def search(self):
        pass

    @abstractmethod
    def delete(self):
        pass

    @abstractmethod
    def modify(self):
        pass

    @abstractmethod
    def sort(self):
        pass

    @abstractmethod
    def total(self):
        pass

    @abstractmethod
    def show(self):
        pass

    @staticmethod
    def quit():
        print('back to selector')
        pass

    @abstractmethod
    def _save(self):
        pass

    @staticmethod
    def help():
        print('supported features: ')
        print(
            '''
    insert
    search
    delete
    modify
    sort
    total
    show
    quit
            '''
        )

    @staticmethod
    def show_students(students: list):
        if not students:
            print('no data found')
            return
        format_title = '{:^6}{:^12}\t{:^8}\t{:^10}\t{:^10}\t{:^10}'
        print(format_title.format('ID', 'name', 'English', 'Python', 'C', 'total'))
        format_data = "{:^6}{:^12}\t{:^12}\t{:^12}\t{:^12}\t{:^12}"
        for info in students:
            score = info.get('score')
            print(
                format_data.format(info.get('id'), info.get('name'), str(score.get('english')),
                                   str(score.get('python')),
                                   str(score.get('c')),
                                   str(score.get('english') + score.get('python') + score.get('c')).center(12)))


class SysFileHandler(SysBaseHandler):
    """
    This class help StudentSys to complete operation
    which implement on file.

    The structure of json file is like example below:
    { id: 'str', name: 'str', score: { english: int, python: int, c: int } }
    """

    def __init__(self, sys):
        super().__init__(sys)
        if not os.path.exists('data'):
            os.mkdir('data')
        self._filename = 'data/' + self._sys.data_name
        try:
            self._load_data()
        except json.JSONDecodeError:
            """
            Check if valid json file. If not, ask user delete it.
            """
            is_delete = input('parse json file error, delete it? (y/n)')
            if is_delete:
                os.remove(self._filename)
                print('done!')

    def insert(self):
        """
        Insert a student data to data file.
        """
        student_list = []
        while True:
            tmp_data = {}

            tmp_data['id'] = input('input id: ')
            if not tmp_data['id']:
                break
            tmp_data['name'] = input('input name: ')
            if not tmp_data['name']:
                break
            try:
                tmp_data['score'] = {}
                tmp_data['score']['english'] = int(input('input English score: '))
                tmp_data['score']['python'] = int(input('input Python score: '))
                tmp_data['score']['c'] = int(input('input Clang score: '))
            except ValueError:
                print('invalid input, except a integer... input again please')
            else:
                student_list.append(tmp_data)
            finally:
                is_continue = input('continue to add? (y/n): ')
                if is_continue != 'y':
                    break
        self._save(student_list)

    def search(self):
        """
        Find information of all students meeting your condition.
        It provides 2 ways to find specific students,
        which include by ID and by name of student.
        """
        student_list, ok = self._load_data()
        if not ok:
            print('data file not found!')

        while True:
            while True:
                try:
                    search_method = \
                        int(input('search by id or name (1/2): ')) - 1
                    m = ('id', 'name')[search_method]
                except IndexError:
                    print('invalid input, try again please!')
                else:
                    search_content = \
                        input('input {} of student: '.format(m))
                    break

            right_student = []
            for student in student_list:
                if student[m] == search_content:
                    right_student.append(student)

            self.show_students(right_student)
            is_continue = input('continue searching? (y/n): ')
            if is_continue != 'y':
                break

    def delete(self):
        pass

    def modify(self):
        pass

    def sort(self):
        pass

    def total(self):
        pass

    def show(self):
        pass

    def _save(self, append_data: list):
        students = self._load_data()[0]
        students += append_data
        self._dump_data(students)

    def _load_data(self):
        """
        Load student data from a json file.
        return 2 value, they are student data and a status code.
        """
        try:
            f = open(self._filename, 'r', encoding='utf-8')
            student_list = json.load(f)
            f.close()
            return student_list, True
        except FileNotFoundError:
            return [], False

    def _dump_data(self, student_list):
        """
        Dump mature data to json file.
        """
        with open(self._filename, 'w', encoding='utf-8') as f:
            json.dump(student_list, f, indent=4)


class SysDatabaseHandler(SysBaseHandler):
    def __init__(self, sys):
        super().__init__(sys)

    def insert(self):
        pass

    def search(self):
        pass

    def delete(self):
        pass

    def modify(self):
        pass

    def sort(self):
        pass

    def total(self):
        pass

    def show(self):
        pass

    def _save(self):
        pass
