// Name: Luis Rios
// Date: 4/25/2026
// File: RecMix.cpp
// Purpose: Creates a simple playlist program.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Base class for all media items
class MediaItem
{
protected:
    string title;
    int durationSeconds;

public:
    MediaItem(string t = "", int d = 0)
    {
        title = t;
        durationSeconds = d;
    }

    virtual void display() const
    {
        cout << "Title: " << title << endl;
        cout << "Duration: " << durationSeconds << " seconds" << endl;
    }
};

// Song adds an artist to the basic media item
class Song : public MediaItem
{
private:
    string artist;

public:
    Song(string t = "", string a = "", int d = 0) : MediaItem(t, d)
    {
        artist = a;
    }

    void display() const override
    {
        cout << "Song: " << title << endl;
        cout << "Artist: " << artist << endl;
        cout << "Duration: " << durationSeconds << " seconds" << endl;
    }

    // Lets a Song object be printed with cout
    friend ostream& operator<<(ostream& os, const Song& s)
    {
        os << "Song: " << s.title
           << " | Artist: " << s.artist
           << " | Duration: " << s.durationSeconds << " seconds";
        return os;
    }
};

// Podcast adds a host name to the basic media item
class Podcast : public MediaItem
{
private:
    string hostName;

public:
    Podcast(string t = "", string h = "", int d = 0) : MediaItem(t, d)
    {
        hostName = h;
    }

    void display() const override
    {
        cout << "Podcast: " << title << endl;
        cout << "Host: " << hostName << endl;
        cout << "Duration: " << durationSeconds << " seconds" << endl;
    }

    // Lets a Podcast object be printed with cout
    friend ostream& operator<<(ostream& os, const Podcast& p)
    {
        os << "Podcast: " << p.title
           << " | Host: " << p.hostName
           << " | Duration: " << p.durationSeconds << " seconds";
        return os;
    }
};

// Template class so the playlist can hold different item types
template <typename T>
class Playlist
{
private:
    vector<T> items;

public:
    void addItem(T item)
    {
        items.push_back(item);
    }

    void removeItem(int index)
    {
        // Makes sure the index is valid before removing
        if (index >= 0 && index < items.size())
        {
            items.erase(items.begin() + index);
        }
    }

    int getSize() const
    {
        return items.size();
    }

    void display() const
    {
        for (int i = 0; i < items.size(); i++)
        {
            cout << i << ". " << items[i] << endl;
        }
    }
};

int main()
{
    // Create playlists using different types
    Playlist<Song> songPlaylist;
    Playlist<Podcast> podcastPlaylist;
    Playlist<string> simplePlaylist;

    // Hard-coded test data
    Song song1("Song One", "Artist A", 200);
    Song song2("Song Two", "Artist B", 180);
    Song song3("Song Three", "Artist C", 220);

    Podcast podcast1("Tech Podcast", "Sam", 1200);
    Podcast podcast2("Gaming Podcast", "Chris", 1500);

    songPlaylist.addItem(song1);
    songPlaylist.addItem(song2);
    songPlaylist.addItem(song3);

    podcastPlaylist.addItem(podcast1);
    podcastPlaylist.addItem(podcast2);

    simplePlaylist.addItem("Study Mix");
    simplePlaylist.addItem("Workout Mix");

    cout << "--- Song Playlist ---" << endl;
    songPlaylist.display();

    cout << endl;

    cout << "--- Podcast Playlist ---" << endl;
    podcastPlaylist.display();

    cout << endl;

    cout << "--- Simple String Playlist ---" << endl;
    simplePlaylist.display();

    cout << endl;

    cout << "--- After Removing One Song ---" << endl;
    songPlaylist.removeItem(1);
    songPlaylist.display();

    return 0;
}