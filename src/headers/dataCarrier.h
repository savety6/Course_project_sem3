#ifndef DATACARRIER_H
#define DATACARRIER_H
class DataCarrier : public Base
{
    private:
        std::string type;
        bool status;
    public:
        void print()override;
        //getters
        std::string getType();
        bool getStatus();
        //setters
        void setType(std::string type);
        void setStatus(bool status);
};
#endif