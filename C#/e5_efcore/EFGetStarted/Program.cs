using Microsoft.EntityFrameworkCore;

using BloggingContext db = new BloggingContext();

Console.WriteLine("1. 删除旧数据库");
db.Database.EnsureDeleted();

Console.WriteLine("2. 创建新数据库和表");
db.Database.EnsureCreated();

Console.WriteLine("3. 插入两条数据");
Blog blog1 = new Blog { Url = "https://example.com/mysql-old" };
Blog blog2 = new Blog { Url = "https://learn.microsoft.com/ef/core" };

db.Blogs.Add(blog1);
db.Blogs.Add(blog2);
db.SaveChanges();

Console.WriteLine("4. 查询当前数据");
foreach (Blog blog in db.Blogs.OrderBy(b => b.BlogId))
{
    Console.WriteLine($"{blog.BlogId}: {blog.Url}");
}

Console.WriteLine("5. 修改第一条数据");
Blog firstBlog = db.Blogs.OrderBy(b => b.BlogId).First();
firstBlog.Url = "https://example.com/mysql-updated";
db.SaveChanges();

Console.WriteLine("6. 删除第二条数据");
Blog secondBlog = db.Blogs.OrderBy(b => b.BlogId).Skip(1).First();
db.Blogs.Remove(secondBlog);
db.SaveChanges();

Console.WriteLine("7. 最终数据库数据");
foreach (Blog blog in db.Blogs.OrderBy(b => b.BlogId))
{
    Console.WriteLine($"{blog.BlogId}: {blog.Url}");
}

Console.WriteLine("验证完成：EF Core 已成功操作 MySQL 数据库。");