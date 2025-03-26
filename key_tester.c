#include "../include/so_long.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"

int	handle_key(int keycode)
{
	ft_printf("you pressed: %d\n", keycode);
	return (0);
}

int	main(void)
{
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 200, 300, "key test");
	mlx_key_hook(win, handle_key, NULL);
	mlx_loop(mlx);
}