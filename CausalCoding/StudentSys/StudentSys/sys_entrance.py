from sys_handler import SysFileHandler, SysDatabaseHandler


class StudentSys(object):
    """
    This class helps to generate a handle of query system.
    """
    def __init__(self, data_name, method='file'):
        self.data_name = data_name
        if method == 'file':
            self._handler = SysFileHandler(self)
        elif method == 'database':
            self._handler = SysDatabaseHandler(self)
        '''
        self._cmd_map = (
            'quit', 'insert', 'search', 'delete',
            'modify', 'sort', 'total', 'show',
        )
        '''

    def send_cmd(self, cmd):
        try:
            getattr(self._handler, cmd)()
        except AttributeError:
            print('invalid command, type "help" to get more info.')
        return cmd != 'quit'
