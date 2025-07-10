#include <iostream>
#include <string>
using namespace std;

struct Song {
    string title;
    Song* next;
    Song* prev;

    Song(string t) : title(t), next(nullptr), prev(nullptr) {}
};

class MusicPlaylist {
private:
    Song* head;
    Song* tail;
    Song* current;

public:
    MusicPlaylist() : head(nullptr), tail(nullptr), current(nullptr) {}

    void addSong(const string& title) {
        Song* newSong = new Song(title);
        if (!head) {
            head = tail = current = newSong;
        } else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
        cout << "Added: " << title << endl;
    }

    void nextSong() {
        if (current && current->next) {
            current = current->next;
            cout << "Now playing: " << current->title << endl;
        } else {
            cout << "You're at the last song." << endl;
        }
    }

    void previousSong() {
        if (current && current->prev) {
            current = current->prev;
            cout << "Now playing: " << current->title << endl;
        } else {
            cout << "You're at the first song." << endl;
        }
    }

    void showCurrent() {
        if (current)
            cout << "Current song: " << current->title << endl;
        else
            cout << "Playlist is empty." << endl;
    }

    void showPlaylist() {
        if (!head) {
            cout << "Playlist is empty." << endl;
            return;
        }
        Song* temp = head;
        cout << "Playlist:\n";
        while (temp) {
            if (temp == current)
                cout << "-> ";
            cout << temp->title << "\n";
            temp = temp->next;
        }
    }

    ~MusicPlaylist() {
        Song* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    MusicPlaylist playlist;

    // 🎵 Adding more songs
    playlist.addSong("Believer");
    playlist.addSong("Shape of You");
    playlist.addSong("Blinding Lights");
    playlist.addSong("Faded");
    playlist.addSong("Levitating");
    playlist.addSong("Senorita");
    playlist.addSong("Perfect");
    playlist.addSong("Closer");
    playlist.addSong("Peaches");
    playlist.addSong("Stay");
    playlist.addSong("Despacito");
    playlist.addSong("Night Changes");

    int choice;
    do {
        cout << "\n--- Music Playlist ---\n";
        cout << "1. Next Song\n";
        cout << "2. Previous Song\n";
        cout << "3. Show Current Song\n";
        cout << "4. Show Playlist\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: playlist.nextSong(); break;
            case 2: playlist.previousSong(); break;
            case 3: playlist.showCurrent(); break;
            case 4: playlist.showPlaylist(); break;
            case 5: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice.\n"; break;
        }
    } while (choice != 5);

    return 0;
}
