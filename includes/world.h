/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:53:09 by khorike           #+#    #+#             */
/*   Updated: 2023/09/07 16:41:14 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "../libft/libft.h"
# include "color.h"

typedef struct s_img
{
	void		*img_ptr;
	int			*data;
	int			bpp;
	int			line_size;
	int			endian;
}				t_img;

typedef struct s_world
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		screen_width;
	int		screen_height;
	t_img	img;
	// t_dlist	*cameras;  // カメラのリスト
	// t_list	*objects;  // 物体のリスト
	// t_color	ambient;  // 環境光の強度
	// t_list	*lights;  // 光源のリスト
}	t_world;

#endif

// bpp:
// bppは"bits per pixel"の略で、1ピクセルあたりのビット数を示します。
// これは画像の色の深さを示しており、たとえば24bppは、
// 8ビットの赤、8ビットの緑、8ビットの青で構成されることを意味します。

// line_size:
// 画像の1行の幅をバイト数で示します。
// この情報を利用することで、2D画像データ内で特定の行にジャンプすることができます。
// これは、ピクセルデータがメモリ内で連続的に配置されている場合に特に有用です。

// endian:
// エンディアンは、バイトの並び順を示す情報です。
// コンピューターアーキテクチャには、ビッグエンディアンとリトルエンディアンという2つの主な方法があり、
// これはデータがメモリにどのように格納されるかを示しています。
// この情報は、外部のソースから画像を読み込む、
// または画像を外部に書き出す際に、正しくデータを解釈するために必要です。