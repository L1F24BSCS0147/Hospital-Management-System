#include <iostream>
#include <fstream>
using namespace std;

void addPatient();
void viewPatients();
void searchPatient();
void updatePatient();
void deletePatient();
void addDoctor();
void viewDoctors();
void searchDoctor();
void addStaff();
void viewStaff();
void searchStaff();
void assignRoom();
void viewRooms();
void releaseRoom();
void bookAppointment();
void viewAppointments();
void generateBill();
void viewBills();
void generateDailyReport();
bool login(const char* roleFile);
void registerUser(const char* roleFile);
void logout();
bool compareStrings(const char* a, const char* b)
{
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] != b[i])
            return false;
        i++;
    }
    return (a[i] == '\0' && b[i] == '\0');
}
void setRoleFile(char roleFile[], const char* name)
{
    int i = 0;
    while (name[i] != '\0')
    {
        roleFile[i] = name[i];
        i++;
    }
    roleFile[i] = '\0';
}
// LOGIN SYSTEM
bool login(const char* roleFile)
{
    char inputUser[50], inputPass[50], fileUser[50], filePass[50];
    cout << "Enter username: ";
    cin >> inputUser;
    bool hasAt = false;
    for (int i = 0; inputUser[i] != '\0'; i++) 
    {
        if (inputUser[i] == '@')
        {
            hasAt = true;
            break;
        }
    }
    if (!hasAt)
    {
        cout << "Invalid username. Must contain '@'.\n";
        return false;
    }
    cout << "Enter password: ";
    cin >> inputPass;
    int length = 0;
    while (inputPass[length] != '\0')
        length++;
    if (length < 8)
    {
        cout << "Invalid password.Must be at least 8 characters.\n";
        return false;
    }
    ifstream fin(roleFile);
    while (fin >> fileUser >> filePass) 
    {
        if (compareStrings(fileUser, inputUser) && compareStrings(filePass, inputPass)) 
        {
            fin.close();
            cout << "Login successful.\n";
            return true;
        }
    }
    fin.close();
    cout << "Login failed. Username or password incorrect." << endl;
    return false;
}
void registerUser(const char* roleFile)
{
    char user[50], pass[50];
    bool valid = false;
    while (!valid) 
    {
        cout << "Enter new username (must include @): ";
        cin >> user;
        bool hasAt = false;
        for (int i = 0; user[i] != '\0'; i++)
        {
            if (user[i] == '@')
            {
                hasAt = true;
                break;
            }
        }
        if (!hasAt)
        {
            cout << "Username must contain '@'. Try again." << endl;
            continue;
        }
        cout << "Enter new password (min 8 characters): ";
        cin >> pass;
        int length = 0;
        while (pass[length] != '\0')
            length++;
        if (length < 8) 
        {
            cout << "Password must be at least 8 characters.Try again." << endl;
            continue;
        }
        valid = true;
    }
    ofstream fout(roleFile, ios::app);
    fout << user << " " << pass << endl;
    fout.close();
    cout << "Registration successful." << endl;
}
void logout() 
{
    cout << "Logged out successfully." << endl;
}
//  Patient Management
void addPatient()
{
    char id[10], name[50], age[5], gender[10], disease[50];
    cout << "Enter Patient ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Gender: ";
    cin >> gender;
    cout << "Enter Disease: ";
    cin.ignore();
    cin.getline(disease, 50);
    ofstream fout("patients.txt", ios::app);
    fout << id << " " << name << " " << age << " " << gender << " " << disease  << endl;
    fout.close();
    cout << "Patient added successfully."<< endl;
}
void viewPatients() 
{
    ifstream fin("patients.txt");
    char id[10], name[50], age[5], gender[10], disease[50];
    while (fin >> id >> name >> age >> gender >> disease )
        cout << "ID: " << id << ", Name: " << name << ", Age: " << age << ", Gender: " << gender << ", Disease: " << disease  << endl;
    fin.close();
}
void searchPatient()
{
    char targetId[10], id[10], name[50], age[5], gender[10], disease[50];
    cout << "Enter Patient ID to search: "; 
    cin >> targetId;
    ifstream fin("patients.txt");
    bool found = false;
    while (fin >> id >> name >> age >> gender >> disease )
    {
        if (compareStrings(id, targetId)) 
        {
            cout << "Found: " << id << " " << name << " " << age << " " << gender << " " << disease  << endl;
            found = true;
        }
    }
    if (!found)
        cout << "Patient not found." << endl;
    fin.close();
}
void updatePatient()
{
    char targetId[10], id[10], name[50], age[5], gender[10], disease[50];
    bool found = false;
    cout << "Enter Patient ID to update: ";
    cin >> targetId;
    ifstream fin("patients.txt");
    ofstream fout("temp.txt");
    while (fin >> id >> name >> age >> gender >> disease)
    {
        if (compareStrings(id, targetId)) 
        {
            found = true;
            cout << "Enter new Name: ";
            cin.ignore();
            cin.getline(name, 50);
            cout << "Enter new Age: ";
            cin >> age;
            cout << "Enter new Gender: ";
            cin >> gender;
            cout << "Enter new Disease: ";
            cin.ignore(); 
            cin.getline(disease, 50);
        }
        fout << id << " " << name << " " << age << " " << gender << " " << disease << endl;
    }
    fin.close();
    fout.close();
    remove("patients.txt");
    rename("temp.txt", "patients.txt");
    if (found)
        cout << "Patient record updated.\n";
    else
        cout << "Patient ID not found.\n";
}
void deletePatient()
{
    char targetId[10], id[10], name[50], age[5], gender[10], disease[50];
    bool found = false;
    cout << "Enter Patient ID to delete: ";
    cin >> targetId;
    ifstream fin("patients.txt");
    ofstream fout("temp.txt");
    while (fin >> id >> name >> age >> gender >> disease) 
    {
        if (!compareStrings(id, targetId)) 
            fout << id << " " << name << " " << age << " " << gender << " " << disease << endl;
        else 
            found = true;
    }
    fin.close();
    fout.close();
    remove("patients.txt");
    rename("temp.txt", "patients.txt");
    if (found)
        cout << "Patient deleted successfully." << endl;
    else
        cout << "Patient ID not found." << endl;
}
//  DOCTOR MANAGEMENT
void addDoctor() 
{
    char id[10], name[50], spec[50];
    cout << "Enter Doctor ID: ";
    cin >> id;
    cout << "Enter Name: "; 
    cin.ignore(); 
    cin.getline(name, 50);
    cout << "Enter Specialization: "; 
    cin.getline(spec, 50);
    ofstream fout("doctors.txt", ios::app);
    fout << id << " " << name << " " << spec << endl;
    fout.close();
    cout << "Doctor added successfully." << endl;
}
void viewDoctors() 
{
    ifstream fin("doctors.txt");
    char id[10], name[50], spec[50];
    while (fin >> id >> name >> spec) 
        cout << "ID: " << id << ", Name: " << name << ", Specialization: " << spec << endl;
    fin.close();
}
void searchDoctor()
{
    char keyword[50], id[10], name[50], spec[50];
    cout << "Enter name or specialization: ";
    cin >> keyword;
    ifstream fin("doctors.txt");
    bool found = false;
    while (fin >> id >> name >> spec) 
    {
        if (compareStrings(name, keyword) || compareStrings(spec, keyword))
        {
            cout << "Doctor: " << id << " " << name << " " << spec << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No match found." << endl;
    fin.close();
}
// Appointment Booking
void bookAppointment()
{
    char appId[10], patId[10], date[15], time[10];
    cout << "Enter Appointment ID: ";
    cin >> appId;
    cout << "Enter Patient ID: ";
    cin >> patId;
    cout << "Enter Date (dd-mm-yyyy): ";
    cin >> date;
    cout << "Enter Time (HH:MM): ";
    cin >> time;
    ifstream check("appointments.txt");
    char aid[10], pid[10], dt[15], tm[10];
    bool alreadyBooked = false;
    while (check >> aid >> pid >> dt >> tm)
    {
        if (compareStrings(pid, patId) && compareStrings(dt, date) && compareStrings(tm, time))
        {
            alreadyBooked = true;
            break;
        }
    }
    check.close();
    if (alreadyBooked)
    {
        cout << "This patient already has an appointment at the given date and time." << endl;
        return;
    }
    ofstream out("appointments.txt", ios::app);
    out << appId << " " << patId << " " << date << " " << time << endl;
    out.close();
    cout << "Appointment booked successfully!" << endl;
}
void viewAppointments()
{
    ifstream fin("appointments.txt");
    char appId[10], patId[10],date[15], time[10];
    while (fin >> appId >> patId >>  date >> time)
        cout << "Appointment ID: " << appId << ", Patient: " << patId <<  ", Date: " << date << ", Time: " << time << endl;
    fin.close();
}
//  Billing System
void generateBill()
{
    char billId[10], patId[10];
    int consult, room, tests;
    cout << "Enter Bill ID: "; 
    cin >> billId;
    cout << "Enter Patient ID: ";
    cin >> patId;
    cout << "Consultation Charges: ";
    cin >> consult;
    cout << "Room Charges: ";
    cin >> room;
    cout << "Test Charges: ";
    cin >> tests;
    int total = consult + room + tests;
    ofstream fout("bills.txt", ios::app);
    fout << billId << " " << patId << " " << consult << " " << room << " " << tests << " " << total << endl;
    fout.close();
    cout << "Total Bill: " << total << endl;
}
void viewBills() 
{
    ifstream fin("bills.txt");
    char billId[10], patId[10];
    int consult, room, test, total;
    while (fin >> billId >> patId >> consult >> room >> test >> total) 
        cout << "Bill ID: " << billId << ", Patient ID: " << patId << ", Total: " << total << endl;
    fin.close();
}
// Room/Ward Management
void assignRoom()
{
    char roomId[10], patientId[10];
    cout << "Enter Room ID: ";
    cin >> roomId;
    cout << "Enter Patient ID: ";
    cin >> patientId;
    ofstream fout("rooms.txt", ios::app);
    fout << roomId << " " << patientId << " occupied" << endl;
    fout.close();
    cout << "Room assigned." << endl;
}
void viewRooms() 
{
    ifstream fin("rooms.txt");
    char roomId[10], patientId[10], status[10];
    while (fin >> roomId >> patientId >> status) 
        cout << "Room: " << roomId << ", Patient: " << patientId << ", Status: " << status << endl;
    fin.close();
}
void releaseRoom()
{
    char targetId[10];
    cout << "Enter Room ID to release: ";
    cin >> targetId;
    ifstream fin("rooms.txt");
    ofstream temp("temp.txt");
    char roomId[10], patientId[10], status[10];
    while (fin >> roomId >> patientId >> status)
    {
        if (compareStrings(roomId, targetId))
            temp << roomId << " vacant vacant" << endl;
        else
            temp << roomId << " " << patientId << " " << status << endl;
    }
    fin.close(); 
    temp.close();
    remove("rooms.txt");
    rename("temp.txt", "rooms.txt");
    cout << "Room released." << endl;
}
//  Staff Management
void addStaff()
{
    char id[10], name[50], role[20];
    cout << "Enter Staff ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "Enter Role (Nurse/Janitor/etc): ";
    cin >> role;
    ofstream fout("staff.txt", ios::app);
    fout << id << " " << name << " " << role << endl;
    fout.close();
    cout << "Staff added." << endl;
}
void viewStaff() 
{
    ifstream fin("staff.txt");
    char id[10], name[50], role[20];
    while (fin >> id >> name >> role)
        cout << "ID: " << id << ", Name: " << name << ", Role: " << role << endl;
    fin.close();
}
void searchStaff() 
{
    char keyword[20], id[10], name[50], role[20];
    cout << "Enter name or role: ";
    cin >> keyword;
    ifstream fin("staff.txt");
    bool found = false;
    while (fin >> id >> name >> role)
    {
        if (compareStrings(name, keyword) || compareStrings(role, keyword)) 
        {
            cout << "Staff: " << id << " " << name << " " << role << endl;
            found = true;
        }
    }
    if (!found) 
        cout << "No match found." << endl;
    fin.close();
}
// Daily Report Generator
void generateDailyReport() 
{
    int patientCount = 0, appointmentCount = 0, billCount = 0, roomActivity = 0;
    ifstream fin1("patients.txt");
    char dummy1[100];
    while (fin1.getline(dummy1, 100))
        patientCount++;
    fin1.close();
    ifstream fin2("appointments.txt");
    while (fin2.getline(dummy1, 100))
        appointmentCount++;
    fin2.close();
    ifstream fin3("bills.txt");
    while (fin3.getline(dummy1, 100))
        billCount++;
    fin3.close();
    ifstream fin4("rooms.txt");
    while (fin4.getline(dummy1, 100))
        roomActivity++;
    fin4.close();
    cout << "--- Daily Report ---\n";
    cout << "New Patients Added: " << patientCount << endl;
    cout << "Appointments Booked: " << appointmentCount << endl;
    cout << "Bills Generated: " << billCount << endl;
    cout << "Rooms Assigned/Released: " << roomActivity << endl;
}
int main() 
{
        int option;
        char roleFile[20];
        cout << "1. Login\n2. Register\nEnter option: ";
        cin >> option;
        cout << "Choose role:\n1. Admin\n2. Doctor\n3. Receptionist\nEnter: ";
        int role;
        cin >> role;
        if (role == 1) 
            setRoleFile(roleFile, "admin.txt");
        else if (role == 2)
            setRoleFile(roleFile, "doctor.txt");
        else
            setRoleFile(roleFile, "receptionist.txt");
        if (option == 1)
        {
            int attempts = 3;
            while (attempts--) 
            {
                if (login(roleFile)) 
                {
                    while (true)
                    {
                        int choice;
                        cout << "\n===== Main Menu =====\n";
                        cout << "1. Add Patient\n2. View Patients\n3. Search Patient\n4. Update Patient\n5. Delete Patient\n";
                        cout << "6. Add Doctor\n7. View Doctors\n8. Search Doctor\n9. Book Appointment\n10. View Appointments\n";
                        cout << "11. Generate Bill\n12. View Bills\n13. Assign Room\n14. View Rooms\n15. Release Room\n";
                        cout << "16. Add Staff\n17. View Staff\n18. Search Staff\n19. Generate Daily Report\n20. Logout\n0. Exit\n";
                        cout << "Enter choice: ";
                        cin >> choice;
                        if (choice == 0 || choice == 20)
                        {
                            logout();
                            break;
                        }
                        switch (choice)
                        {
                        case 1:
                            addPatient();
                            break;
                        case 2:
                            viewPatients();
                            break;
                        case 3: 
                            searchPatient();
                            break;
                        case 4:
                            updatePatient();
                            break;
                        case 5:
                            deletePatient(); 
                            break;
                        case 6:
                            addDoctor();
                            break;
                        case 7:
                            viewDoctors();
                            break;
                        case 8:
                            searchDoctor();
                            break;
                        case 9: 
                            bookAppointment();
                            break;
                        case 10:
                            viewAppointments();
                            break;
                        case 11:
                            generateBill();
                            break;
                        case 12: 
                            viewBills();
                            break;
                        case 13: 
                            assignRoom();
                            break;
                        case 14:
                            viewRooms();
                            break;
                        case 15:
                            releaseRoom();
                            break;
                        case 16:
                            addStaff();
                            break;
                        case 17:
                            viewStaff();
                            break;
                        case 18: 
                            searchStaff(); 
                            break;
                        case 19:
                            generateDailyReport();
                            break;
                        default:
                            cout << "Invalid option!\n";
                            break;
                        }
                    }
                    break;
                }
                else 
                    cout << "Attempts left: " << attempts << endl;
            }
        }
        else if 
            (option == 2) registerUser(roleFile);
        return 0;
 }