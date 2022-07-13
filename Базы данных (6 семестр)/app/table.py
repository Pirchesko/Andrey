# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'table.ui'
#
# Created by: PyQt5 UI code generator 5.15.6
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from unittest import result
from PyQt5 import QtCore, QtGui, QtWidgets
import cx_Oracle
from PyQt5.QtWidgets import QTableWidgetItem

class Ui_MainWindow_table(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.setWindowModality(QtCore.Qt.NonModal)
        MainWindow.resize(800, 600)
        MainWindow.setMinimumSize(QtCore.QSize(0, 0))
        MainWindow.setMaximumSize(QtCore.QSize(16777215, 16777210))
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.centralwidget)
        self.verticalLayout.setObjectName("verticalLayout")
        self.layout_input = QtWidgets.QVBoxLayout()
        self.layout_input.setObjectName("layout_input")
        self.layout_parametr_1 = QtWidgets.QHBoxLayout()
        self.layout_parametr_1.setObjectName("layout_parametr_1")
        self.label_1 = QtWidgets.QLabel(self.centralwidget)
        self.label_1.setMinimumSize(QtCore.QSize(110, 0))
        font = QtGui.QFont()
        font.setPointSize(9)
        self.label_1.setFont(font)
        self.label_1.setObjectName("label_1")
        self.layout_parametr_1.addWidget(self.label_1)
        self.line_1 = QtWidgets.QLineEdit(self.centralwidget)
        self.line_1.setObjectName("line_1")
        self.layout_parametr_1.addWidget(self.line_1)
        self.layout_input.addLayout(self.layout_parametr_1)
        self.layout_parametr_2 = QtWidgets.QHBoxLayout()
        self.layout_parametr_2.setObjectName("layout_parametr_2")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setMinimumSize(QtCore.QSize(110, 0))
        font = QtGui.QFont()
        font.setPointSize(9)
        self.label_2.setFont(font)
        self.label_2.setObjectName("label_2")
        self.layout_parametr_2.addWidget(self.label_2)
        self.line_2 = QtWidgets.QLineEdit(self.centralwidget)
        self.line_2.setObjectName("line_2")
        self.layout_parametr_2.addWidget(self.line_2)
        self.layout_input.addLayout(self.layout_parametr_2)
        self.layout_parametr_3 = QtWidgets.QHBoxLayout()
        self.layout_parametr_3.setObjectName("layout_parametr_3")
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setMinimumSize(QtCore.QSize(110, 0))
        font = QtGui.QFont()
        font.setPointSize(9)
        self.label_3.setFont(font)
        self.label_3.setObjectName("label_3")
        self.layout_parametr_3.addWidget(self.label_3)
        self.line_3 = QtWidgets.QLineEdit(self.centralwidget)
        self.line_3.setObjectName("line_3")
        self.layout_parametr_3.addWidget(self.line_3)
        self.layout_input.addLayout(self.layout_parametr_3)
        self.verticalLayout.addLayout(self.layout_input)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setMaximumSize(QtCore.QSize(16777215, 21))
        font = QtGui.QFont()
        font.setPointSize(9)
        self.label.setFont(font)
        self.label.setObjectName("label")
        self.horizontalLayout_2.addWidget(self.label)
        self.button_input = QtWidgets.QPushButton(self.centralwidget)
        self.button_input.setMaximumSize(QtCore.QSize(93, 16777215))
        font = QtGui.QFont()
        font.setPointSize(9)
        self.button_input.setFont(font)
        self.button_input.setObjectName("button_input")
        self.horizontalLayout_2.addWidget(self.button_input)
        self.verticalLayout.addLayout(self.horizontalLayout_2)
        self.verticalLayout_2 = QtWidgets.QVBoxLayout()
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.tableWidget = QtWidgets.QTableWidget(self.centralwidget)
        self.tableWidget.setShowGrid(True)
        self.tableWidget.setGridStyle(QtCore.Qt.SolidLine)
        self.tableWidget.setWordWrap(True)
        self.tableWidget.setCornerButtonEnabled(False)
        self.tableWidget.setRowCount(0)
        self.tableWidget.setColumnCount(0)
        self.tableWidget.setObjectName("tableWidget")
        item = QtWidgets.QTableWidgetItem()
        font = QtGui.QFont()
        font.setFamily("MS Shell Dlg 2")
        font.setPointSize(9)
        item.setFont(font)
        self.tableWidget.setHorizontalHeaderItem(0, item)
        self.verticalLayout_2.addWidget(self.tableWidget)
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.comboBox = QtWidgets.QComboBox(self.centralwidget)
        self.comboBox.setMaximumSize(QtCore.QSize(16777215, 28))
        font = QtGui.QFont()
        font.setPointSize(9)
        self.comboBox.setFont(font)
        self.comboBox.setObjectName("comboBox")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.horizontalLayout.addWidget(self.comboBox)
        self.button_show = QtWidgets.QPushButton(self.centralwidget)
        self.button_show.setEnabled(True)
        self.button_show.setMinimumSize(QtCore.QSize(0, 30))
        self.button_show.setMaximumSize(QtCore.QSize(93, 16777215))
        font = QtGui.QFont()
        font.setPointSize(9)
        self.button_show.setFont(font)
        self.button_show.setObjectName("button_show")
        self.horizontalLayout.addWidget(self.button_show)
        self.verticalLayout_2.addLayout(self.horizontalLayout)
        self.verticalLayout.addLayout(self.verticalLayout_2)
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "Таблицы"))
        self.button_input.setText(_translate("MainWindow", "Ввести"))
        self.tableWidget.setSortingEnabled(False)
        self.comboBox.setItemText(0, _translate("MainWindow", "Выберете таблицу"))
        self.comboBox.setItemText(1, _translate("MainWindow", "cars"))
        self.comboBox.setItemText(2, _translate("MainWindow", "people"))
        self.button_show.setText(_translate("MainWindow", "Смотреть"))
        
        self.input_default()
        self.button_show.clicked.connect(self.select_show)
        self.button_input.clicked.connect(self.select_input)   

    def input_default(self):
        _translate = QtCore.QCoreApplication.translate
        self.label.setText(_translate("MainWindow", "Введите параметры или посмотрите таблицу"))
        self.label_1.setText(_translate("MainWindow", "1 параметр"))
        self.label_2.setText(_translate("MainWindow", "2 параметр"))
        self.label_3.setText(_translate("MainWindow", "3 параметр"))
        item = self.tableWidget.horizontalHeaderItem(0)
        self.tableWidget.setRowCount(0)
        self.tableWidget.setColumnCount(0)
        #item.setText(_translate("MainWindow", "Колонка"))

    def select_show(self):
        _translate = QtCore.QCoreApplication.translate
        if self.comboBox.currentText() == "Выберете таблицу":
            self.input_default()
        else:
            str_table = self.comboBox.currentText()
            if (str_table == "cars"):
                self.tableWidget.setColumnCount(3)
                self.label_1.setText(_translate("MainWindow", "Марка"))
                self.label_2.setText(_translate("MainWindow", "Тип транпорта"))
                self.label_3.setText(_translate("MainWindow", "Пробег"))
            if (str_table == "people"):
                self.tableWidget.setColumnCount(3)
                self.label_1.setText(_translate("MainWindow", "Фамилия"))
                self.label_2.setText(_translate("MainWindow", "Имя"))
                self.label_3.setText(_translate("MainWindow", "Отчество"))
            
            dsn_tns = cx_Oracle.makedsn('localhost', '1521', service_name='orcl') 
            conn = cx_Oracle.connect(user='test', password='111', dsn=dsn_tns) 
            mycursor = conn.cursor()
            mycursor.execute(str(open('table_get.txt').read().split(';')[0]).encode().decode('utf8').encode('cp1251').decode('utf8').format(str_table))
            result = mycursor.fetchall()

            if mycursor.rowcount > 0:
                self.label.setText(QtCore.QCoreApplication.translate("MainWindow", "Найдено по таблице \"" + str_table + "\" " + str(mycursor.rowcount) + " строк"))
            else:
                self.label.setText(QtCore.QCoreApplication.translate("MainWindow", "Ничего не найдено по этой таблице: " + str_table))
            self.tableWidget.setRowCount(0)

            for row_number, row_data in enumerate(result):
                self.tableWidget.insertRow(row_number)
                for column_number, data in enumerate(row_data):
                    if (column_number != 0):
                        data_str = str(data)
                        if data_str == "None":
                            data_str = ""
                        self.tableWidget.setItem(row_number, column_number - 1, QTableWidgetItem(data_str))
            mycursor.close()
            conn.close()

    def select_input(self):
        _translate = QtCore.QCoreApplication.translate
        str_table = self.comboBox.currentText()
        if str_table == "Выберете таблицу":
            self.label.setText(_translate("MainWindow", "Введите параметры или посмотрите таблицу"))
        else:
            param = []
            if (str_table == "cars"):
                if (self.line_1.text() == ""):
                    param.append("Марка")
                if (self.line_2.text() == ""):
                    param.append("Тип транспорта")
                if (self.line_3.text() == ""):
                    param.append("Пробег")
            if (str_table == "people"):
                if (self.line_1.text() == ""):
                    param.append("Фамилия")
                if (self.line_2.text() == ""):
                    param.append("Имя")
            param_count = len(param)
            if (param_count > 0):
                str_input_err = "Проверьте, чтобы параметр(ы): "
                for i in range(param_count):
                    str_input_err += "\"" + param[i] + "\" "
                self.label.setText(QtCore.QCoreApplication.translate("MainWindow", str_input_err))
            else:
                try: 
                    dsn_tns = cx_Oracle.makedsn('localhost', '1521', service_name='orcl') 
                    conn = cx_Oracle.connect(user='test', password='111', dsn=dsn_tns) 
                    mycursor = conn.cursor()
                    if (str_table == "cars"):
                        mycursor.execute(str(open('table_set.txt').read().split(';')[0]).encode().decode('utf8').encode('cp1251').decode('utf8').format(str_table, str_table, "'" + self.line_1.text() + "'", "'" + self.line_2.text() + "'", self.line_3.text())) 
                    if (str_table == "people"):
                        print("people")
                        mycursor.execute(str(open('table_set.txt').read().split(';')[0]).encode().decode('utf8').encode('cp1251').decode('utf8').format(str_table, str_table, "'" + self.line_1.text() + "'", "'" + self.line_2.text() + "'", "'" + self.line_3.text() + "'")) 
                    conn.commit()
                    mycursor.close()
                    conn.close()

                    self.label.setText(QtCore.QCoreApplication.translate("MainWindow", "Добавлено в таблицу \"" + str_table + "\": " + self.line_1.text() + " " + self.line_2.text() + " " + self.line_3.text()))


                except conn.Error as e:
                    self.error_dialog = QtWidgets.QErrorMessage()
                    self.error_dialog.showMessage(str(e))
        self.tableWidget.setRowCount(0)
        self.tableWidget.setColumnCount(0)



if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow_table()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
