#include "common.h"
#include "mem.h"

void read_file(Page* page, const char* filename) {
	LOG("\nREAD_FILE\n");
	FILE* f = fopen(filename, "rb");
	if (f == NULL) {
		return;
	}

	while (1) {
		Line line = new_line();
		line.size = getline(&line.buf, &line.cap, f);
		LOG("getline size-[%d] cap-[%d]\n", line.size, line.cap);

		if (line.size == -1) {
			break;
		}

		add_line(page, line, page->size);
	}

	fclose(f);
}

void write_file(Page* page) {
}
