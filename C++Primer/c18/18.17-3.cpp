namespace Exercise {
    int ivar = 0;
    double dvar = 0;
    const int limit = 1000;
}

int ivar = 0;

using namespace Exercise;

int main() {
    double dvar = 3.1415;
    int iobj = limit + 1;
    // ++ivar;
    ++::ivar;
    return 0;
}
