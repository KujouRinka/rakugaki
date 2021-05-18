import os
from sys_entrance import StudentSys
__version__ = '0.0.1'


class PreHandler(object):
    def __init__(self):
        self._handlers = {}

    def send_cmd(self, *par):
        try:
            return getattr(self, par[0])(*par[1:])
        except (AttributeError, PermissionError):
            if len(par[0]) != 0:
                print('invalid command, type "help" to get more info')

    def use(self, hd=None):
        if hd is None:
            print('you have these handles:')
            for key in self._handlers.keys():
                print('\t{}'.format(key))
            print()
        else:
            try:
                return self._handlers[hd], hd
            except KeyError:
                print('handle {} not exist'.format(hd))
                return None

    def create(self, hd=None, data_name=None, method='file'):
        if hd is None or data_name is None:
            print('invalid usage, type "help" to get more info')
            return

        is_overwritten = 'y'
        if hd in self._handlers:
            is_overwritten = \
                input('{} exist, overwritten it? (y/n)'.format(hd))

        if is_overwritten == 'y':
            self._handlers[hd] = StudentSys(data_name, method)
        print('create {} successfully'.format(hd))

    @staticmethod
    def help():
        print('supported operation:')
        print(
            '''
    create handle data_src [method=file]
    use [handle]
    quit
            '''
        )

    @staticmethod
    def quit():
        print('bye!')
        exit(0)


def pre_cmd(pre_handler: PreHandler):
    return pre_handler.send_cmd(*input().strip().split(' '))


def send(handle: StudentSys, hd):
    print('now you have entered into handle: {}'.format(hd))
    while handle.send_cmd(input('{} >>> '.format(hd)).strip()):
        pass


def main():
    print('Student system {}, Type "help" to get more info'.format(__version__))
    print('working on:', os.getcwd())
    pre_handler = PreHandler()
    while True:
        print('>>> ', end='')
        par = pre_cmd(pre_handler)
        if par is not None:
            send(*par)


if __name__ == '__main__':
    main()
