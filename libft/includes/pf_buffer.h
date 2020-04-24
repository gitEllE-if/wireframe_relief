#ifndef PF_BUFFER_H
# define PF_BUFFER_H

# include <stdint.h>

# define FW_WRITE	0x1
# define FW_BUFSIZ	1024

typedef struct		s_file
{
	unsigned short	mode;
	short			desc;
	unsigned char	*buf;
	unsigned char	*buf_end;
	unsigned char	*next;
	unsigned char	*end;
	unsigned char	buf_1c;
}					t_file;

size_t				ft_fwrite(const void *ptr, size_t s, size_t nel, t_file *f);
int32_t				ft_fflush(t_file *str);

#endif
