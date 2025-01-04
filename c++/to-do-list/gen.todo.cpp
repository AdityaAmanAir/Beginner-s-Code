// gcc your_program.c -o your_program `pkg-config --cflags --libs gtk+-3.0`


#include <gtk/gtk.h>
#include <iostream>
#include <vector>
#include <string>

// Global variables for simplicity
std::vector<std::string> tasks;
GtkWidget *listbox;

// Function to add a task
void add_task(const gchar *task) {
    tasks.push_back(task);
    GtkWidget *row = gtk_list_box_row_new();
    GtkWidget *label = gtk_label_new(task);
    gtk_container_add(GTK_CONTAINER(row), label);
    gtk_list_box_insert(GTK_LIST_BOX(listbox), row, -1);
}

// Callback for the add button
void on_add_button_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(g_object_get_data(G_OBJECT(widget), "entry"));
    const gchar *task = gtk_entry_get_text(GTK_ENTRY(entry));
    if (task && task[0]) {
        add_task(task);
        gtk_entry_set_text(GTK_ENTRY(entry), "");
    }
}

// Main function to setup the GUI
int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "To-Do List");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 600, 600);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);


    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Entry for new tasks
    GtkWidget *entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), entry, TRUE, TRUE, 0);

    // Add button
    GtkWidget *button = gtk_button_new_with_label("Add Task");
    g_signal_connect(button, "clicked", G_CALLBACK(on_add_button_clicked), NULL);
    g_object_set_data(G_OBJECT(button), "entry", entry);
    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);

    // Listbox for tasks
    listbox = gtk_list_box_new();
    gtk_box_pack_start(GTK_BOX(vbox), listbox, TRUE, TRUE, 0);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}