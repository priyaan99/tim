#include "common.h"
#include "mem.h"

void read_file(Page* page, const char* filename) {
	LOG("\nREAD_FILE\n");
	FILE* f = fopen(filename, "rb");
	if (f == NULL) {
        LOGx("Err :: cannot open file [%s]\n", filename);
		return;
	}

	while (1) {
		Line line = new_line();
		line.size = getline(&line.buf, &line.cap, f);
		LOGx("getline size-[%d] cap-[%d]\n", line.size, line.cap);

		if (line.size == -1) {
			break;
		}

		add_line(page, line, page->size);
	}

	fclose(f);
}

void write_file(Page* page, const char* filename) {
	LOG("\nWRITE_FILE\n");
	FILE* f = fopen(filename, "wb+");
	if (f == NULL) {
        LOGx("Err :: cannot open file [%s]\n", filename);
		return;
	}

    size_t bytes_read;
    for (int i = 0; i < page->size; i++) {
        bytes_read = fwrite(page->lines[i].buf, sizeof(char), page->lines[i].size, f);

        if (bytes_read < page->lines[i].size) {
            LOG("Err :: cannot write to file [%s] line [%ld]", filename, i);
        }

        if (bytes_read == -1) {
            LOG("Err :: failed write to file [%s]\n", filename);
            break;
        }
    }

	fclose(f);
}



