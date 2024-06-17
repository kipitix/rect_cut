#include <QtTest>

// add necessary includes here

class Domain : public QObject
{
    Q_OBJECT

public:
    Domain();
    ~Domain();

private slots:
    void test_case1();
};

Domain::Domain() {}

Domain::~Domain() {}

void Domain::test_case1() {}

QTEST_APPLESS_MAIN(Domain)

#include "tst_domain.moc"
