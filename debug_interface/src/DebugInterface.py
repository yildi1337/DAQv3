####################################################################################################
#
# DebugInterface.py
#
# Tool for graphical display of status information and for controlling the DAQ v3 hardware via the 
# virtual serial interface (second USB-B port).
#
# pd, 2022-09-23
#
####################################################################################################
import PySimpleGUI as sg
import serial
import serial.tools.list_ports_windows
import time

# global constants
SYSTEM_COLOR = '#f0f0f0'
LABEL_WIDTH = 15
INPUT_WIDTH = 20
RADIO_WIDTH = INPUT_WIDTH - 5
CHECKBOXLABEL_WIDTH = 20
CHECKBOX_WIDTH = 7
SLEEP_TIME = 0.25

GROUP_ID_ACNV_INPUT_TYPE_CH1_RADIO = 1
GROUP_ID_ACNV_INPUT_TYPE_CH2_RADIO = 2
GROUP_ID_ACNV_CHASSIS_CONNECTION_RADIO = 3

# global variables
ser = serial.Serial()

# function executed when clicking on "System Reset" button
def button_system_reset():
    if ser.is_open:
        ser.write(bytes("SYSTEM_RESET;", encoding='utf8'))
        ser.flush()
        time.sleep(10*SLEEP_TIME)

# function executed when clicking on "Get Values" button
def button_get_values():
    get_parameter_radio('ACNV_GET_INPUT_TYPE_CH1;', 'key_acnv_input_type_ch1_int', 'key_acnv_input_type_ch1_ext', 'INT', 'EXT')
    get_parameter_radio('ACNV_GET_INPUT_TYPE_CH2;', 'key_acnv_input_type_ch2_int', 'key_acnv_input_type_ch2_ext', 'INT', 'EXT')
    get_parameter_radio('ACNV_GET_CHASSIS_CONNECTION;', 'key_acnv_chassis_connection_float', 'key_acnv_chassis_connection_gnd', 'FLOAT', 'GND')

# function executed when clicking on "Set Values" button
def button_set_values():
    set_parameter_radio('key_acnv_input_type_ch1_int', 'ACNV_SET_INPUT_TYPE_CH1 INT;')
    set_parameter_radio('key_acnv_input_type_ch1_ext', 'ACNV_SET_INPUT_TYPE_CH1 EXT;')
    set_parameter_radio('key_acnv_input_type_ch2_int', 'ACNV_SET_INPUT_TYPE_CH2 INT;')
    set_parameter_radio('key_acnv_input_type_ch2_ext', 'ACNV_SET_INPUT_TYPE_CH2 ENT;')
    set_parameter_radio('key_acnv_chassis_connection_float', 'ACNV_SET_CHASSIS_CONNECTION FLOAT;')
    set_parameter_radio('key_acnv_chassis_connection_gnd', 'ACNV_SET_CHASSIS_CONNECTION GND;')

# function for getting a parameter from the device and writing the result to the GUI
def get_parameter(command, key):
    window[key].update("0")
    window.Refresh()
    if ser.is_open:
        ser.write(bytes(command, encoding='utf8'))
        ser.flush()
        time.sleep(SLEEP_TIME)
        inbytes = ser.in_waiting
        if inbytes > 0:
            instring = str(ser.read(inbytes)).replace("b'", "").replace("\\n'", "")
            window[key].update(instring)

# function for setting a parameter
def set_parameter(command):
    if ser.is_open:
        ser.write(bytes(command, encoding='utf8'))
        ser.flush()
        time.sleep(SLEEP_TIME)
        inbytes = ser.in_waiting
        ser.read(inbytes)

# function for getting a set of parameters and updating the according radio buttons
def get_parameter_radio(command, key1, key2, val1, val2):
    if ser.is_open:
        ser.write(bytes(command, encoding='utf8'))
        ser.flush()
        time.sleep(SLEEP_TIME)
        inbytes = ser.in_waiting
        if inbytes > 0:
            instring = str(ser.read(inbytes)).replace("b'", "").replace("\\n'", "")
            window[key1].update(False)
            window[key2].update(False)
            if (instring == val1):
                window[key1].update(True)
            if (instring == val2):
                window[key2].update(True)

# function for setting the input type of channel 1
def set_parameter_radio(key, command1):
    time.sleep(SLEEP_TIME)
    if ser.is_open:
        if (bool(values[key]) == True):
            ser.write(bytes(command1, encoding='utf8'))
            ser.flush()
            time.sleep(SLEEP_TIME)
            inbytes = ser.in_waiting
            ser.read(inbytes)

# set standard color theme
sg.theme('SystemDefault')

# get list of available serial ports
comports = []
ports = serial.tools.list_ports_windows.comports()
for i in range(0, len(ports)):
    comports.append(ports[i].device)

# layout of left column
column_connection_settings = [  
            [ sg.Text('') ],
            [ sg.Text('_____ Connection Settings _____') ],
            [ sg.Text('Port:', size=(LABEL_WIDTH,1)), sg.InputCombo(comports, default_value=comports[0], size=(INPUT_WIDTH-2,1), key='key_comports') ],
            [ sg.Text('Symbol rate [Bd]:', size=(LABEL_WIDTH,1)), sg.Input('115200', size=(INPUT_WIDTH,1), key='key_symbol_rate_Bd') ],
            [ sg.Text('Data bits:', size=(LABEL_WIDTH,1)), sg.Input('8', size=(INPUT_WIDTH,1), key='key_databits') ],
            [ sg.Text('Parity:', size=(LABEL_WIDTH,1)), sg.InputCombo(['None', 'Even', 'Odd'], default_value='None', size=(INPUT_WIDTH-2,1), key='key_parity') ],
            [ sg.Text('Stop bits:', size=(LABEL_WIDTH,1)), sg.Input('1', size=(INPUT_WIDTH,1), key='key_stopbits') ],
            [ sg.Text('Status:', size=(LABEL_WIDTH,1)), sg.Input('Disconnected', size=(INPUT_WIDTH,1), readonly=True, key='key_connection_status') ],
            [ sg.Text('') ],
            [ sg.Button('Exit', disabled=False, key='key_button_exit'), sg.Button('Connect', disabled=False, key='key_button_connect'), sg.Button('Disconnect', disabled=True, key='key_button_disconnect') ],
            [ sg.Button('System Reset', disabled=True, key='key_button_system_reset'), sg.Button('Get Values', disabled=True, key='key_button_get_values'), sg.Button('Set Values', disabled=True, key='key_button_set_values') ],
]

# layout of center column
column_analog_conversion_v3 = [             
            [ sg.Text('__________ AnalogConversion_v3 __________') ],            
            [ sg.Text('') ],
            [ sg.Text('_____ Input Type _____') ],            
            [ sg.Text('Channel 1:', size=(LABEL_WIDTH,1)), sg.Radio('Intern', size=(RADIO_WIDTH,1), disabled=True, group_id=GROUP_ID_ACNV_INPUT_TYPE_CH1_RADIO, key='key_acnv_input_type_ch1_int') ],
            [ sg.Text('', size=(LABEL_WIDTH,1)), sg.Radio('Extern', size=(RADIO_WIDTH,1), disabled=True, group_id=GROUP_ID_ACNV_INPUT_TYPE_CH1_RADIO, key='key_acnv_input_type_ch1_ext') ],
            [ sg.Text('Channel 2:', size=(LABEL_WIDTH,1)), sg.Radio('Intern', size=(RADIO_WIDTH,1), disabled=True, group_id=GROUP_ID_ACNV_INPUT_TYPE_CH2_RADIO, key='key_acnv_input_type_ch2_int') ],
            [ sg.Text('', size=(LABEL_WIDTH,1)), sg.Radio('Extern', size=(RADIO_WIDTH,1), disabled=True, group_id=GROUP_ID_ACNV_INPUT_TYPE_CH2_RADIO, key='key_acnv_input_type_ch2_ext') ],
            [ sg.Text('') ],
            [ sg.Text('_____ Chassis Connection _____') ],            
            [ sg.Radio('Floating Mode', size=(RADIO_WIDTH,1), disabled=True, group_id=GROUP_ID_ACNV_CHASSIS_CONNECTION_RADIO, key='key_acnv_chassis_connection_float') ],
            [ sg.Radio('Grounded Mode', size=(RADIO_WIDTH,1), disabled=True, group_id=GROUP_ID_ACNV_CHASSIS_CONNECTION_RADIO, key='key_acnv_chassis_connection_gnd') ],
]

# overall layout
layout = [
    [
        sg.Column(column_connection_settings, element_justification='c'),
        sg.VSeperator(),
        sg.Column(column_analog_conversion_v3, element_justification='c')
    ]
]

# create new window
window = sg.Window("DAQ v3 | Debug Interface | pd (2022)", layout, finalize=True, margins=(25, 25), location=(100,150))

# run
while True:

    event, values = window.read()

    # connect to selected serial port
    if event == "key_button_connect":
        if not ser.is_open:
            ser.port = values['key_comports']
            ser.baudrate = float(values['key_symbol_rate_Bd'])
            ser.bytesize = float(values['key_databits'])
            if values['key_parity'] == 'None':
                ser.parity = serial.PARITY_NONE
            elif values['key_parity'] == 'Even':
                ser.parity = serial.PARITY_EVEN
            elif values['key_parity'] == 'Odd':
                ser.parity = serial.PARITY_ODD            
            ser.stopbits = float(values['key_stopbits'])            

            ser.open()
            if ser.is_open:
                window['key_connection_status'].update('Connected')
                window['key_button_connect'].update(disabled=True)
                window['key_button_disconnect'].update(disabled=False)
                window['key_button_get_values'].update(disabled=False)
                window['key_button_set_values'].update(disabled=False)
                window['key_button_system_reset'].update(disabled=False)
            else:
                window['key_connection_status'].update('Connection error')
                window['key_button_connect'].update(disabled=False)
                window['key_button_disconnect'].update(disabled=True)
                window['key_button_get_values'].update(disabled=True)
                window['key_button_set_values'].update(disabled=True)
                window['key_button_system_reset'].update(disabled=True)

    # system reset
    if event == "key_button_system_reset":
        window['key_button_connect'].update(disabled=True)
        window['key_button_disconnect'].update(disabled=True)
        window['key_button_get_values'].update(disabled=True)
        window['key_button_set_values'].update(disabled=True)
        window['key_button_system_reset'].update(disabled=True)
        button_system_reset()
        button_get_values()
        window['key_button_connect'].update(disabled=True)
        window['key_button_disconnect'].update(disabled=False)
        window['key_button_get_values'].update(disabled=False)
        window['key_button_set_values'].update(disabled=False)
        window['key_button_system_reset'].update(disabled=False)

    # get values
    if event == "key_button_get_values":
        window['key_button_connect'].update(disabled=True)
        window['key_button_disconnect'].update(disabled=True)
        window['key_button_get_values'].update(disabled=True)
        window['key_button_set_values'].update(disabled=True)
        window['key_button_system_reset'].update(disabled=True)
        button_get_values()
        window['key_button_connect'].update(disabled=True)
        window['key_button_disconnect'].update(disabled=False)
        window['key_button_get_values'].update(disabled=False)
        window['key_button_set_values'].update(disabled=False)
        window['key_button_system_reset'].update(disabled=False)

        window['key_acnv_input_type_ch1_int'].update(disabled=False)
        window['key_acnv_input_type_ch1_ext'].update(disabled=False)
        window['key_acnv_input_type_ch2_int'].update(disabled=False)
        window['key_acnv_input_type_ch2_ext'].update(disabled=False)
        window['key_acnv_chassis_connection_float'].update(disabled=False)
        window['key_acnv_chassis_connection_gnd'].update(disabled=False)

    # set values
    if event == "key_button_set_values":
        window['key_button_connect'].update(disabled=True)
        window['key_button_disconnect'].update(disabled=True)
        window['key_button_get_values'].update(disabled=True)
        window['key_button_set_values'].update(disabled=True)
        window['key_button_system_reset'].update(disabled=True)
        button_set_values()
        button_get_values()
        window['key_button_connect'].update(disabled=True)
        window['key_button_disconnect'].update(disabled=False)
        window['key_button_get_values'].update(disabled=False)
        window['key_button_set_values'].update(disabled=False)
        window['key_button_system_reset'].update(disabled=False)

    # disconnect serial port
    if event == "key_button_disconnect":
        if ser.is_open:
            ser.close()
        if not ser.is_open:
            window['key_connection_status'].update('Disonnected')
            window['key_button_connect'].update(disabled=False)
            window['key_button_disconnect'].update(disabled=True)
            window['key_button_get_values'].update(disabled=True)
            window['key_button_set_values'].update(disabled=True)
            window['key_button_system_reset'].update(disabled=True)

        window['key_acnv_input_type_ch1_int'].update(disabled=True)
        window['key_acnv_input_type_ch1_ext'].update(disabled=True)
        window['key_acnv_input_type_ch2_int'].update(disabled=True)
        window['key_acnv_input_type_ch2_ext'].update(disabled=True)
        window['key_acnv_chassis_connection_float'].update(disabled=True)
        window['key_acnv_chassis_connection_gnd'].update(disabled=True)

    # disconnect serial port and exit
    if event == "key_button_exit" or event == sg.WIN_CLOSED:
        if ser.is_open:
            ser.close()
        break

window.close()
