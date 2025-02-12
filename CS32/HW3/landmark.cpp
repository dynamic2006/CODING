class Landmark
{
    public:
        Landmark(string name) : m_name(name){}
        virtual ~Landmark(){cout << " " << name() << "." << endl;}

        virtual string color() const{
            return "yellow";
        }
        virtual string icon() const = 0;
        string name() const{
            return m_name;
        }

    private:
        string m_name;
};

class Hotel : public Landmark
{
    public:
        Hotel(string name): Landmark(name){}
        ~Hotel(){cout << "Destroying the hotel";}
        
        string icon() const{
            return "bed";
        }
};

class Restaurant : public Landmark
{
    public:
        Restaurant(string name, int cap): Landmark(name), m_cap(cap){}
        ~Restaurant(){cout << "Destroying the restaurant";}

        string icon() const{
            if(m_cap < 40) return "small knife/fork";
            return "large knife/fork";
        }

    private:
        int m_cap;
};

class Hospital : public Landmark
{
    public:
        Hospital(string name): Landmark(name){}
        ~Hospital(){cout << "Destroying the hospital";}

        string color() const{
            return "blue";
        }
        string icon() const{
            return "H";
        }
};
