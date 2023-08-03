#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

class Element
{
public:
    double data;
    Element *next;
    Element *prew;
};

class Liste
{
public:
    Liste()
    {
        head = nullptr;
        tail = nullptr;

        numElements = 0;
    }

    bool empty()
    {
        return (head == nullptr) && (tail == nullptr);
    }

    double get_back() const
    {
        if (tail) // alt: tail != nullptr
        {
            return tail->data;
        }
        else
        {
            std::cout << "ERROR: Element not found!" << std::endl;
            return std::numeric_limits<double>::quiet_NaN();
        }
    }

    double get_front() const
    {
        if (head) // alt: head != nullptr
        {
            return head->data;
        }
        else
        {
            std::cout << "ERROR: Element not found!" << std::endl;
            return std::numeric_limits<double>::quiet_NaN();
        }
    }

    double at(int i)
    {
        if (empty())
        {
            std::cout << "ERROR: Element not found!" << std::endl;
        }
        else
        {
            Element *temp = head;
            for (int z = 0; z < i; ++z)
            {
                if (temp)
                {
                    temp = temp->next;
                }
            }
            if (temp)
            {
                return temp->data;
            }
        }
    }

    void size()
    {
        std::cout << "size: " << numElements << std::endl;
    }

    void pop_front()
    {
        if (empty())
        {
            std::cout << "ERROR: Element not found!" << std::endl;
        }
        else
        {
            Element *temp = head;
            head = head->next;
            head->prew = nullptr;
            delete temp;
            --numElements;
        }
    }

    void pop_back()
    {
        if (empty())
        {
            std::cout << "ERROR: Element not found!" << std::endl;
        }
        else
        {
            Element *temp = tail;
            tail = tail->prew;
            tail->next = nullptr;
            delete temp;
            --numElements;
        }
    }

    void push_front(double wert)
    {
        if (empty())
        {
            Element *temp = new Element;
            temp->data = wert;

            head = temp;
            tail = temp;

            temp->next = nullptr;
            temp->prew = nullptr;

            ++numElements;
        }
        else if (numElements == 1)
        {
            Element *temp = new Element;
            temp->data = wert;

            head = temp;
            tail->prew = temp;

            temp->next = tail;
            temp->prew = nullptr;

            ++numElements;
        }
        else // numElements > 1 Element
        {
            Element *temp = new Element;
            temp->data = wert;

            temp->next = head;
            temp->prew = nullptr;

            head = temp;
            head->next->prew = head;

            ++numElements;
        }
    }

    void push_back(double wert)
    {
        if (empty())
        {
            push_front(wert);

            ++numElements;
        }
        else if (numElements == 1)
        {
            Element *temp = new Element;
            temp->data = wert;

            head->next = temp;
            tail = temp;

            temp->next = nullptr;
            temp->prew = head;

            ++numElements;
        }
        else // numElements > 1 Element
        {
            Element *temp = new Element;
            temp->data = wert;

            temp->prew = tail;
            temp->next = nullptr;

            tail = temp;
            tail->prew->next = tail;

            ++numElements;
        }
    }

    void ausgabe(std::string table) const
    {
        if (table == "head")
        {
            std::cout << "HEAD\n";
            std::cout << "==============================\n";
            std::cout << std::setw(14) << "H.addr"
                      << "   " << std::setw(9) << "H.data"
                      << "     " << std::setw(14) << "H.next\n\n";
            std::cout << head << "\n\n";
            Element *H_temp = head;

            while (H_temp)
            {
                std::cout << H_temp;
                std::cout << "   " << std::setw(9) << H_temp->data;
                std::cout << "   " << std::setw(14) << H_temp->next << std::endl;

                H_temp = H_temp->next;
            }
            std::cout << "==============================\n\n";
        }
        else if (table == "tail")
        {
            std::cout << "TAIL\n";
            std::cout << "==============================\n";
            std::cout << std::setw(14) << "T.addr"
                      << "   " << std::setw(9) << "T.data"
                      << "     " << std::setw(14) << "T.prew\n\n";
            std::cout << tail << "\n\n";
            Element *T_temp = tail;

            while (T_temp)
            {
                std::cout << T_temp;
                std::cout << "   " << std::setw(9) << T_temp->data;
                std::cout << "   " << std::setw(14) << T_temp->prew << std::endl;

                T_temp = T_temp->prew;
            }
            std::cout << "==============================\n\n";
        }
    }

private:
    Element *head;
    Element *tail;

    // Anzahl der Elemente
    int numElements;
};

int main()
{
    const std::string head = "head";
    const std::string tail = "tail";
    Liste l;
    l.push_front(155);
    l.push_front(1288134);
    l.push_back(999945);
    l.pop_front();
    try
    {
        l.ausgabe("head");
        l.ausgabe("tail");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}