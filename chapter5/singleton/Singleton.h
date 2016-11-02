#ifndef __HEADER_H__
#define __HEADER_H__


namespace CythonBook {

    class MySingleton {
    public:
        static MySingleton& getInstance() {
            static MySingleton s;
            return s;
        }

        int getValue() const { return m_value; }

    private:
        
        MySingleton(): m_value(1234) { }

        int m_value;
    };
    
};

#endif //__HEADER_H__
