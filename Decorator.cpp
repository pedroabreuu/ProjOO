#include <iostream>
#include <string>
#include <memory>

class Bebida {
public:
    virtual ~Bebida() = default;
    virtual std::string descricaoBebida() const = 0;
    virtual double calculaCusto() const = 0;
};

class CafeExpresso : public Bebida {
public:
    std::string descricaoBebida() const override {
        return "Café Expresso";
    }

    double calculaCusto() const override {
        return 5.0;
    }
};

class Cappuccino : public Bebida {
public:
    std::string descricaoBebida() const override {
        return "Cappuccino";
    }

    double calculaCusto() const override {
        return 8.0;
    }
};

class Cha : public Bebida {
public:
    std::string descricaoBebida() const override {
        return "Cha";
    }

    double calculaCusto() const override {
        return 4.0;
    }
};

class DecoratorBebida : public Bebida {
protected:
    std::unique_ptr<Bebida> bebida;

public:
    explicit DecoratorBebida(std::unique_ptr<Bebida> b)
        : bebida(std::move(b)) {}
};

class Leite : public DecoratorBebida {
public:
    explicit Leite(std::unique_ptr<Bebida> b)
        : DecoratorBebida(std::move(b)) {}

    std::string descricaoBebida() const override {
        return bebida->descricaoBebida() + " + Leite";
    }

    double calculaCusto() const override {
        return bebida->calculaCusto() + 2.0;
    }
};

class Chantily : public DecoratorBebida {
public:
    explicit Chantily(std::unique_ptr<Bebida> b)
        : DecoratorBebida(std::move(b)) {}

    std::string descricaoBebida() const override {
        return bebida->descricaoBebida() + " + Chantily";
    }

    double calculaCusto() const override {
        return bebida->calculaCusto() + 2.5;
    }
};

class Canela : public DecoratorBebida {
public:
    explicit Canela(std::unique_ptr<Bebida> b)
        : DecoratorBebida(std::move(b)) {}

    std::string descricaoBebida() const override {
        return bebida->descricaoBebida() + " + Canela";
    }

    double calculaCusto() const override {
        return bebida->calculaCusto() + 1.0;
    }
};

class CaldaChocolate : public DecoratorBebida {
public:
    explicit CaldaChocolate(std::unique_ptr<Bebida> b)
        : DecoratorBebida(std::move(b)) {}

    std::string descricaoBebida() const override {
        return bebida->descricaoBebida() + " + Calda de Chocolate";
    }

    double calculaCusto() const override {
        return bebida->calculaCusto() + 3.0;
    }
};

int main() {
    std::unique_ptr<Bebida> bebida1 = std::make_unique<CafeExpresso>();
    bebida1 = std::make_unique<Leite>(std::move(bebida1));
    bebida1 = std::make_unique<Canela>(std::move(bebida1));

    std::cout << bebida1->descricaoBebida() << '\n';
    std::cout << "Custo: R$ " << bebida1->calculaCusto() << "\n\n";

    std::unique_ptr<Bebida> bebida2 = std::make_unique<Cha>();
    bebida2 = std::make_unique<Chantily>(std::move(bebida2));
    bebida2 = std::make_unique<CaldaChocolate>(std::move(bebida2));

    std::cout << bebida2->descricaoBebida() << '\n';
    std::cout << "Custo: R$ " << bebida2->calculaCusto() << '\n';

    return 0;
}