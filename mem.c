#include "defs.h"

extern uint32_t TEXT_START;
extern uint32_t TEXT_END;

extern uint32_t RODATA_START;
extern uint32_t RODATA_END;

extern uint32_t DATA_START;
extern uint32_t DATA_END;

extern uint32_t BSS_START;
extern uint32_t BSS_END;

extern uint32_t HEAP_START;
extern uint32_t HEAP_END;


#define PAGE_SIZE  4096
#define PAGE_ORDER 12		// 2^12=4096

#define PAGE_FLAG_TAKEN	((uint8_t)(1 << 0))
#define PAGE_FLAG_LAST	((uint8_t)(1 << 1))

typedef struct page_s{
	uint8_t flags;
} page_t;

static inline void _clear(page_t *page)
{
	page->flags = 0;
}

static inline BOOL _is_free(page_t *page)
{
	return !(page->flags & PAGE_FLAG_TAKEN);
}

static inline BOOL _is_last(page_t *page)
{
	return page->flags & PAGE_FLAG_LAST;
}

static inline void set_flag(page_t *page, uint8_t flags)
{
	page->flags |= flags;
}

void mem_page_init()
{	
	printf("TEXT_START: \n");		
	printf("TEXT_END:   \n");	
	printf("RODATA_START: \n");
	printf("RODATA_END:   \n");
	printf("DATA_START: \n");
	printf("DATA_END:   \n");
	printf("BSS_END:   \n");
	printf("BSS_END:   \n");
}

void* mem_page_alloc(int npages)
{
	return NULL;
}

void mem_page_free(void *p)
{

}

