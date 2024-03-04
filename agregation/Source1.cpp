#include <iostream>
#include <string>

using namespace std;

class CPU 
{
string model;
int cores;
int threads;

public:
    CPU(string m, int c, int t) : model(m), cores(c), threads(t) {}

    void printDetails() 
    {
        cout << "CPU Model: " << model << endl;
        cout << "Number of Cores: " << cores << endl;
        cout << "Number of Threads: " << threads << endl;
    }
};

class RAM 
{
int capacity;
string memoryType;

public:
    RAM(int cap, string type) : capacity(cap), memoryType(type) {}

    void printDetails() 
    {
        cout << "RAM Capacity: " << capacity << " GB" << endl;
        cout << "Memory Type: " << memoryType << endl;
    }
};

class HDD 
{
int capacity;
string type;

public:
    HDD(int cap, string t) : capacity(cap), type(t) {}

    void printDetails() 
    {
        cout << "HDD Capacity: " << capacity << " GB" << endl;
        cout << "HDD Type: " << type << endl;
    }
};

class GPU 
{
string model;
int vram;

public:
    GPU(string m, int v) : model(m), vram(v) {}

    void printDetails() 
    {
        cout << "GPU Model: " << model << endl;
        cout << "VRAM: " << vram << " GB" << endl;
    }
};

class Display 
{
float size;
string resolution;

public:
    Display(float s, string r) : size(s), resolution(r) {}

    void printDetails() 
    {
        cout << "Display Size: " << size << " inches" << endl;
        cout << "Resolution: " << resolution << endl;
    }
};

class Battery 
{
int capacity;

public:
    Battery(int cap) : capacity(cap) {}

    void printDetails() 
    {
        cout << "Battery Capacity: " << capacity << " Wh" << endl;
    }
};

class Port 
{
string type;
int speed;

public:
    Port(string t, int s) : type(t), speed(s) {}

    void printDetails() 
    {
        cout << "Port Type: " << type << endl;
        cout << "Speed: " << speed << " Gbps" << endl;
    }
};

class Laptop 
{
CPU* cpu;
RAM* ram;
HDD* hdd;
GPU* gpu;
Display display;
Battery battery;
Port* ports;
int numPorts;

public:
    Laptop(CPU* c, RAM* r, HDD* h, GPU* g, Display d, Battery b, Port* p, int n) : cpu(c), ram(r), hdd(h), gpu(g), display(d), battery(b), ports(p), numPorts(n) {}

    ~Laptop() 
    {
        delete cpu;
        delete ram;
        delete hdd;
        delete gpu;
        delete[] ports;
    }

    void printSpecifications() 
    {
        cout << "Laptop Specifications:" << endl;
        cpu->printDetails();
        ram->printDetails();
        hdd->printDetails();
        gpu->printDetails();
        display.printDetails();
        battery.printDetails();
        cout << "Ports:" << endl;
        for (int i = 0; i < numPorts;i++) 
        {
            ports[i].printDetails();
        }
    }
};

int main() 
{
    CPU* cpu = new CPU("Intel Core i7", 4, 8);
    RAM* ram = new RAM(16, "DDR4");
    HDD* hdd = new HDD(512, "SSD");
    GPU* gpu = new GPU("NVIDIA GeForce RTX 3060", 6);
    Display display(15.6, "1920x1080");
    Battery battery(70);
    Port* ports = new Port[3]{ Port("USB-C", 10), Port("HDMI", 8), Port("USB-A", 5) };

    Laptop laptop(cpu, ram, hdd, gpu, display, battery, ports, 3);
    laptop.printSpecifications();

    delete cpu;
    delete ram;
    delete hdd;
    delete gpu;
    delete[] ports;

    return 0;
}