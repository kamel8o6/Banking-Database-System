# Makefile for Banking System Project

# اسم الملف التنفيذي
TARGET = banking

# الكومبايلر
CXX = g++
CXXFLAGS = -std=c++17 -g

# ملفات السورس
SRCS = main.cpp

# القاعدة الأساسية
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
