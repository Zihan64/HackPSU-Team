#include <gtk/gtk.h>
#include "finance.h"
Record records[MAX_RECORDS];
int count = 0;
GtkWidget *entry_desc;
GtkWidget *entry_amount;
GtkWidget *text_view;
//When "Add Record" button is clicked
void on_add_clicked(GtkButton *button, gpointer user_data) {
    const char *desc = gtk_entry_get_text(GTK_ENTRY(entry_desc));
    const char *amount_str = gtk_entry_get_text(GTK_ENTRY(entry_amount));

    if (desc[0] == '\0' || amount_str[0] == '\0') {
        gtk_text_buffer_set_text(
            gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view)),
            "Please enter both description and amount.",
            -1
        );
        return;
    }
    double amount = atof(amount_str);
    addRecord(records, &count, desc, amount);

    // Clear input fields
    gtk_entry_set_text(GTK_ENTRY(entry_desc), "");
    gtk_entry_set_text(GTK_ENTRY(entry_amount), "");

    gtk_text_buffer_set_text(
        gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view)),
        "Record added successfully!",
        -1
    );
}
// When "Show Summary" button is clicked
void on_summary_clicked(GtkButton *button, gpointer user_data) {
    char summary[2048];
    showSummary(records, count, summary, sizeof(summary));
    gtk_text_buffer_set_text(
        gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view)),
        summary,
        -1
    );
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    // Create the main window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Weekly Finance Tracker");
    gtk_window_set_default_size(GTK_WINDOW(window), 420, 320);
    // Create a grid layout
    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);
    // Create input fields and buttons
    entry_desc = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_desc), "Description (e.g., lunch / salary)");

    entry_amount = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_amount), "Amount (+ for income / - for expense)");

    GtkWidget *btn_add = gtk_button_new_with_label("Add Record");
    GtkWidget *btn_summary = gtk_button_new_with_label("Show Summary");

    text_view = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);
    gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(text_view), FALSE);

    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    // Place widgets in the grid
    gtk_grid_attach(GTK_GRID(grid), entry_desc, 0, 0, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_amount, 0, 1, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), btn_add, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), btn_summary, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), text_view, 0, 3, 2, 1);
    // Connect signals
    g_signal_connect(btn_add, "clicked", G_CALLBACK(on_add_clicked), NULL);
    g_signal_connect(btn_summary, "clicked", G_CALLBACK(on_summary_clicked), NULL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}